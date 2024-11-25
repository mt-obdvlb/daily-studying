const http = require('http')
const server = http.createServer()

server.on('request', (req, res) => {
    res.setHeader('Content-Type', 'text/plain;charset=utf-8')
    res.end('welcome使用')
})

server.listen(3000, () => {
    console.log('启动成功');
    
})