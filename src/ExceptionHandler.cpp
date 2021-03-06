#include <string.h>
#include <stdio.h>
#include "ExceptionHandler.h"
#include "TestResult.h"
#include "Failure.h"
#include "TestException.h"

#if _MSC_VER >= 1400
#   define snprintf(buf, size, format, ...) _snprintf_s(buf, size, _TRUNCATE, format, __VA_ARGS__)
#endif


namespace ExceptionHandler {


namespace {
    bool g_bHandleExceptions = true;
}


bool IsOn ()
{
    return g_bHandleExceptions;
}

void TurnOn (bool bOn)
{
    g_bHandleExceptions = bOn;
}


void Handle (TestResult& result, const TestException& exception, 
             const char* testname, const char* filename, int linenumber )
{
    char msg[4096];
    snprintf(msg, sizeof(msg), "Raised exception %s from:\n  %s(%i)", exception.message, exception.file, exception.line);
    result.AddFailure (Failure (msg, testname, filename, linenumber));
}

void Handle (TestResult& result, const char* condition, 
             const char* testname, const char* filename, int linenumber)
{
    if (!g_bHandleExceptions) 
        throw;
        
    char msg[1024] = "Unhandled exception ";
    strncat(msg, condition, sizeof(msg)-32);
    result.AddFailure (Failure (msg, testname, filename, linenumber));
}



}
