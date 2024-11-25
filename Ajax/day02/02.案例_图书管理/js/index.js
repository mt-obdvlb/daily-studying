/**
 * 目标1：渲染图书列表
 *  1.1 获取数据
 *  1.2 渲染数据
 */
const creator = 'mto'

function getBooksList() {
    axios({
        url: 'http://hmajax.itheima.net/api/books',
        params: {
            creator
        }
    }).then(res => {
        console.log(res)
        const booksList = res.data.data
        document.querySelector('.list').innerHTML = booksList.map((b, i) => `<tr>
          <td>${i + 1}</td>
          <td>${b.bookname}</td>
          <td>${b.author}</td>
          <td>${b.publisher}</td>
          <td data-id=${b.id}>
            <span class="del">删除</span>
            <span class="edit">编辑</span>
          </td>
        </tr>`).join('')
    })
}

getBooksList()

const addModalDom = document.querySelector('.add-modal')
const addModal = new bootstrap.Modal(addModalDom)

document.querySelector('.add-btn').addEventListener('click', () => {
    const addForm = document.querySelector('.add-form')
    const bookObj = serialize(addForm, { hash: 1, empty: 1 })
    console.log(bookObj)
    // const {bookname, author, publisher} = bookObj
    axios({
        url: 'http://hmajax.itheima.net/api/books',
        method: 'post',
        data: {
            ...bookObj,
            creator,
        }
    }).then(res => {
        getBooksList()
        addForm.reset()
        addModal.hide()
    })
    // getBooksList()
})

document.querySelector('.list').addEventListener('click', e => {
    if (e.target.classList.contains('del')) {
        const id = e.target.parentNode.dataset.id
        axios({
            url: `http://hmajax.itheima.net/api/books/${id}`,
            method: 'delete'
        }).then(res => {
            getBooksList()
        })
    }
})

const editModalDom = document.querySelector('.edit-modal')
const editModal = new bootstrap.Modal(editModalDom)
document.querySelector('.list').addEventListener('click', e => {
    if (e.target.classList.contains('edit')) {
        editModal.show()
        const id = e.target.parentNode.dataset.id
        axios({
            url: `http://hmajax.itheima.net/api/books/${id}`,

        }).then(res => {
            const bookObj = res.data.data
            const keys = Object.keys(bookObj)
            keys.forEach(key => {
                document.querySelector(`.edit-form .${key}`).value = bookObj[key]
            })
        })
    }
})

document.querySelector('.edit-btn').addEventListener('click', () => {
    const editForm = document.querySelector('.edit-form')
    const { bookname, author, publisher, id } = bookObj =serialize(editForm, { hash: 1, empty: 1 })
    console.log(bookObj);
 
    axios({
        url: `http://hmajax.itheima.net/api/books/${id}`,
        method: 'put',
        data: {
            bookname,
            author,
            publisher,
            creator,
        }
    }).then(res => {
        console.log(res)

        getBooksList()
    })
    editModal.hide()
})