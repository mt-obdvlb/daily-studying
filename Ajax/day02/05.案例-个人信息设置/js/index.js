/**
 * 目标1：信息渲染
 *  1.1 获取用户的数据
 *  1.2 回显数据到标签上
 * */

const creator = 'mto'

function getInfo() {
    axios({
        url: 'http://hmajax.itheima.net/api/settings',
        params: {
            creator,
        }
    }).then(res => {
        console.log(res)
        const userObj = res.data.data
        Object.keys(userObj).forEach(key => {
            if (key === 'avatar') {
                document.querySelector('.prew').src = userObj[key]
            } else if (key === 'gender') {
                const genderList = document.querySelectorAll('.gender')
                genderList[userObj[key]].checked = 1
            } else {
                document.querySelector(`.${key}`).value = userObj[key]
            }
        })

    })
}

getInfo()

document.querySelector('#upload').addEventListener('change', e => {
    const img = e.target.files[0]
    const fd = new FormData()
    fd.append('avatar', img)
    fd.append('creator', creator)
    axios({
        url: 'http://hmajax.itheima.net/api/avatar',
        method: 'put',
        data: fd,
    }).then(res => {
        getInfo()
    })
})
const toastDom = document.querySelector('.my-toast')
const toast = new bootstrap.Toast(toastDom)

document.querySelector('.submit').addEventListener('click', () => {
    const userForm = document.querySelector('.user-form')
    const userObj = serialize(userForm, { hash: 1, empty: 1 })
    console.log(userObj)
    userObj.creator = creator
    userObj.gender = +userObj.gender
    axios({
        url: 'http://hmajax.itheima.net/api/settings',
        method: 'put',
        data: userObj
    }).then(res => {
        getInfo()
        toast.show()
    })
})