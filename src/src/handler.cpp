#include <sblog/get_html.h>
#include <sblog/handler.h>

#include <oatpp/web/protocol/http/outgoing/ResponseFactory.hpp>

namespace sblog
{
    Handler::Handler() : content_{sblog::getHtml("./blog.md")}
    {
    }

    std::shared_ptr<OutgoingResponse> Handler::handle(const std::shared_ptr<IncomingRequest> &request)
    {
        static_cast<void>(request);

        using ResponseFactory = oatpp::web::protocol::http::outgoing::ResponseFactory;

        if (content_.empty())
        {
            return ResponseFactory::createResponse(Status::CODE_204, "No content found.");
        }
        return ResponseFactory::createResponse(Status::CODE_200, content_.c_str());
    }
}
