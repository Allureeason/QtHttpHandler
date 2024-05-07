#ifndef __HTTP_MESSAGE_BASE_H__
#define __HTTP_MESSAGE_BASE_H__

#include <QString>

class IHttpMsgBase
{
public:
    IHttpMsgBase() = default;
    virtual ~IHttpMsgBase() = default;

    virtual void parseJson(const QString& json) = 0;
    virtual QString packJson() const = 0;

    void setHttpMsgBase(IHttpMsgBase* base) { m_base = base; }

protected:
    IHttpMsgBase* m_base = nullptr;
};

class HttpMsgRequest : public IHttpMsgBase
{
public:
    HttpMsgRequest() = default;
    virtual ~HttpMsgRequest() = default;

    virtual void parseJson(const QString& json) override;
    virtual QString packJson() const override;
    
};

class HttpMsgResponse : public IHttpMsgBase
{
public:
    HttpMsgResponse() = default;
    virtual ~HttpMsgResponse() = default;

    virtual void parseJson(const QString& json) override;
    virtual QString packJson() const override;
    
private:
    QString m_session;
    QString m_message;
    int64_t m_code = 0;
};

#endif // __HTTP_MESSAGE_BASE_H__
