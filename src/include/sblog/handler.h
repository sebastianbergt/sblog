#ifndef SBLOG_HANDLER_H
#define SBLOG_HANDLER_H

#include <string>
#include <oatpp/web/server/HttpRequestHandler.hpp>
#include <oatpp/web/protocol/http/outgoing/Response.hpp>
#include <oatpp/web/protocol/http/incoming/Request.hpp>

namespace sblog
{

    using OutgoingResponse = oatpp::web::protocol::http::outgoing::Response;
    using IncomingRequest = oatpp::web::protocol::http::incoming::Request;

    class Handler : public oatpp::web::server::HttpRequestHandler
    {
    public:
        Handler();

        std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest> &request) override;

    private:
        const std::string content_;
    };

} // namespace sblog

#endif // SBLOG_HANDLER_H
