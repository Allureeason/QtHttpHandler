#include "protocol/test.h"
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();


    HttpMsgTestReq testMsg;
    testMsg.setName("busy");
    testMsg.setAge(24);

    HttpMsgRequest req;
    req.setHttpMsgBase(&testMsg);


    /**
     * url + method  ==> 确定一条协议 cmd
     *
     * [register]
     *  cmd -> HttpMsgHandler
     *          |
     *          |
     *          --> [x] handleRequest(HttpMsgRequest req) // 处理请求, 一般服务端用
     *          |
     *          --> [√] handleResponse(HttpResponse resp) // 处理响应, 一般客户端用
     *          |
     *          --> [√] sendRequest(HttpMsgRequest req) // 发送请求, 一般客户端用
     *          |
     *          --> [x]sendResponse(HttpMsgResponse resp) // 发送响应, 一般服务端用
     *
     *  HttpMsgHandleMsg
     *          |
     *          |
     *          --> onHttpMsg()
     *          |
     *          --> sendHttpMsg()
     * */


    qDebug() << req.packJson();

    return a.exec();
}
