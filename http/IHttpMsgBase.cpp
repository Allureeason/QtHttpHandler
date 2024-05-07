#include "IHttpMsgBase.h"

#include <QJsonDocument>
#include <QJsonObject>

void HttpMsgRequest::parseJson(const QString& json)
{
    if(m_base)
        m_base->parseJson(json);
}

QString HttpMsgRequest::packJson() const
{
    if(m_base)
    {
        QJsonDocument doc;
        QJsonObject obj;
        obj["data"] = m_base->packJson();
        doc.setObject(obj);
        return doc.toJson();
    }

    return "{}";
}

void HttpMsgResponse::parseJson(const QString& json)
{
    if(m_base)
        m_base->parseJson(json);
}

QString HttpMsgResponse::packJson() const
{
    if(m_base)
    {
        QJsonDocument doc;
        QJsonObject obj;
        obj["message"] = m_message;
        obj["session"] = m_session;
        obj["code"] = m_code;
        obj["data"] = m_base->packJson();
        doc.setObject(obj);
        return doc.toJson();
    }

    return "{}";
}
