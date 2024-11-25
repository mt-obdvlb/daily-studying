/**
 * 目标：基于 CommonJS 标准语法，导入工具属性和方法使用
 */
// 导入
const obj = require('./utils.js')
console.log(obj)
const res = obj.arraySum([1, 2, 3, 4, 5, 6])
console.log(res)
