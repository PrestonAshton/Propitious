#ifndef PROPITIOUS_COMMON_CHARSETS_HPP
#define PROPITIOUS_COMMON_CHARSETS_HPP

namespace Propitious
{
#if defined(UNICODE)
#define PROPITIOUS_CHARSET_UNICODE
#else
#define PROPITIOUS_CHARSET_ANSI
#endif
}

#endif