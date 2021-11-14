#include <memory>
#include <string>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <sblog/get_html.h>
#include <maddy/parser.h>

namespace sblog
{
    const std::string getHtml(const std::string &markdown_file_path) noexcept
    {
        try
        {
            std::ifstream input_file(markdown_file_path);
            if (input_file.fail())
            {
                std::cerr << "Markdown could not be opened:" << markdown_file_path << "\n";
                return "";
            }

            std::stringstream markdownInput{};
            markdownInput << input_file.rdbuf();
            // config (is optional)
            const auto config = std::make_shared<maddy::ParserConfig>();
            config->isEmphasizedParserEnabled = true; // default
            config->isHTMLWrappedInParagraph = true;  // default
            // parsing
            auto parser = std::make_shared<maddy::Parser>(config);
            const auto html = parser->Parse(markdownInput);
            return html;
        }
        catch (...)
        {
            std::cerr << "Parsing markdown file for html output failed.\n";
            return "";
        }
    }

} // namespace sblog
