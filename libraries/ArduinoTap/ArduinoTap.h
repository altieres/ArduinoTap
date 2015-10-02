
#ifndef ArduinoTap_h
#define ArduinoTap_h

#ifdef ARDUINO
#include <Stream.h>
#else
#include <cstdlib>
#include <iostream>
class Stream
{
  public:
    Stream (std::ostream& _os) { os = &_os; }
    ~Stream () {}
    inline void print(const char s[]) { *os << s; }
    inline void print(const char c) { *os << c; }
    inline void print(const int i) { *os << i; }
    inline void print(const double d) { *os << d; }

    inline void println(const char s[]) { *os << s << std::endl; }
    inline void println(const char c) { *os << c << std::endl; }
    inline void println(const int i) { *os << i << std::endl; }
    inline void println(const double d) { *os << d << std::endl; }
    inline void println() { *os << std::endl; }

    inline void flush() { os->flush(); }
  private:
    std::ostream* os;
};
#endif


extern void plan(const int nb);
extern int plan(void);
extern void no_plan(void);
extern void skip_all(const char *const reason);
extern void done_testing(void);
extern void done_testing(const int nb);
extern void bail_out(const char *const reason=NULL);
extern void _ok(bool test, const char *const file, int line, const char *const name=NULL);
extern void todo(const char *const reason=NULL, const int count=1);
extern void skip(const char *const reason=NULL, const int count=1);
extern void todo_skip(const char *const reason=NULL);
extern void skip_rest(const char *const reason=NULL);
extern void diag(const char *const msg);
extern void output(Stream &out);
extern Stream &output(void);
extern void failure_output(Stream &out);
extern Stream &failure_output(void);
extern bool is_passing(void);

#define ok(test, ...)                   _ok((test), __FILE__, __LINE__, ##__VA_ARGS__)
#define nok(test, ...)                  _ok(!(test), __FILE__, __LINE__, ##__VA_ARGS__)
#define pass(...)                       _ok(true, __FILE__, __LINE__, ##__VA_ARGS__)
#define fail(...)                       _ok(false, __FILE__, __LINE__, ##__VA_ARGS__)
#define is(got, expected, ...) \
    { \
        bool e = (got) == (expected); \
        _ok(e, __FILE__, __LINE__, ##__VA_ARGS__); \
        if (! e) { \
            Stream &out = output(); \
            out.print("#         got: "); \
            out.println(got); \
            out.print("#    expected: "); \
            out.println(expected); \
        } \
    }
#define isnt(got, expected, ...) \
    { \
        bool e = (got) != (expected); \
        _ok(e, __FILE__, __LINE__, ##__VA_ARGS__); \
        if (! e) { \
            Stream &out = output(); \
            out.print("#         got: "); \
            out.println(got); \
            out.println("#    expected: anything else"); \
        } \
    }


#endif

