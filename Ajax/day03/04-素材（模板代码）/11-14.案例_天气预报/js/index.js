/**
 * 目标1：默认显示-北京市天气
 *  1.1 获取北京市天气数据
 *  1.2 数据展示到页面
 */

function getWeather(cityCode) {
    myAxios({
        url: 'http://hmajax.itheima.net/api/weather',
        params: {
            city: cityCode
        },
    }).then(res => {
        console.log(res)
        const wObj = res.data
        Object.keys(wObj).forEach(key => {
            if (key === 'dayForecast') {
                document.querySelector('.week-wrap').innerHTML = wObj[key].map(item => `<li class="item">
          <div class="date-box">
            <span class="dateFormat">${item.dateFormat}</span>
            <span class="date">${item.date}</span>
          </div>
          <img src="${item.weatherImg}" alt="" class="weatherImg">
          <span class="weather">${item.weather}</span>
          <div class="temp">
            <span class="temNight">${item.temNight}</span>-
            <span class="temDay">${item.temDay}</span>
            <span>℃</span>
          </div>
          <div class="wind">
            <span class="windDirection">${item.windDirection}</span>
            <span class="windPower">${item.windPower}</span>
          </div>
        </li>`).join(``)
            } else if (key === 'weatherImg') {
                document.querySelector('.weatherImg').src = wObj[key]
            } else if (key === 'todayWeather') {
                Object.keys(wObj[key]).forEach(key => {
                    document.querySelector(`.${key}`).innerHTML = wObj['todayWeather'][key]
                })
            } else {
                document.querySelector(`.${key}`).innerHTML = wObj[key]

            }
        })
    })
}

getWeather('110100')

document.querySelector('.search-city').addEventListener('input', e => {
    myAxios({
        url: 'http://hmajax.itheima.net/api/weather/city',
        params: {
            city: e.target.value,
        }
    }).then(res => {
        // console.log(res);
        
        document.querySelector('.search-list').innerHTML = res.data.map(item => `<li class="city-item" data-code="${item.code}">${item.name}</li>`).join('')
    })
})

document.querySelector('.search-list').addEventListener('click', e => {
    console.log(1);
    
    if (e.target.classList.contains('city-item')) {
        console.log(e.target);
        
        const cityCode = e.target.dataset.code
        getWeather(cityCode)
    }
})