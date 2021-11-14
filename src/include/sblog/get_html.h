#ifndef SBLOG_GET_HTML_H
#define SBLOG_GET_HTML_H

#include <string>

namespace sblog
{
    const std::string getHtml(const std::string &markdown_file_path) noexcept;
} // namespace sblog

#endif // SBLOG_GET_HTML_H
