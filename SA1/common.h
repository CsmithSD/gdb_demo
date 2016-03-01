#ifndef __COMMON_H
#define __COMMON_H

#ifdef DEBUG
#define TRACE_ON \
cout << "<" << __func__ << ">\n";

#define TRACE_OFF \
cout << "</" << __func__ << ">\n";
#else
#define TRACE_ON
#define TRACE_OFF
#endif

#ifdef DEBUG
#define ENTRY(X) \
   cout << __func__ << "(" << X << ") line: " << __LINE__ << "\n";

#define EXIT(X) \
   cout << "Returning from " << __func__ << "(" << X << ") line: " << __LINE__ << "\n";
#else
#define ENTRY(X)
#define EXIT(X)
#endif
#endif
