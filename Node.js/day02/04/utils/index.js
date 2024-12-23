/**
 * 本文件是，utils 工具包的唯一出口
 * 作用：把所有工具模块方法集中起来，统一向外暴露
 */
const { getArraySum } = require('./lib/arr.js')
const { checkPwd, checkUser } = require('./lib/str.js')

module.exports = {
  getArraySum,
  checkPwd,
  checkUser,
}