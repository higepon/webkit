/*
 * Copyright (C) 2011 Higepon(Taro Minowa)  <higepon@users.sourceforge.jp>
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#include "config.h"
#include "FileSystem.h"

#include "NotImplemented.h"
#include "PlatformString.h"
#include <wtf/text/CString.h>

namespace WebCore {

String homeDirectoryPath()
{
  return "/USER";
}

String openTemporaryFile(const String&, PlatformFileHandle& handle)
{
    notImplemented();
    handle = invalidPlatformFileHandle;
    return String();
}

void closeFile(PlatformFileHandle&)
{
    notImplemented();
}

int writeToFile(PlatformFileHandle, const char* data, int length)
{
    notImplemented();
    return 0;
}

bool unloadModule(PlatformModule)
{
    notImplemented();
    return false;
}

bool deleteFile(const String&)
{
    notImplemented();
    return false;
}

bool fileExists(const String& path)
{
    notImplemented();
    return false;
}

String pathGetFileName(const String& pathName)
{
    if (pathName.isEmpty())
        return pathName;

    // CString tmpFilename = fileSystemRepresentation(pathName);
    // GOwnPtr<gchar> baseName(g_path_get_basename(tmpFilename.data()));
    // return String::fromUTF8(baseName.get());
    notImplemented();
}

String directoryName(const String& path)
{
    // String name = path.left(path.length() - pathGetFileName(path).length());
    // if (name.characterStartingAt(name.length() - 1) == '\\') {
    //     // Remove any trailing "\".
    //     name.truncate(name.length() - 1);
    // }
    // return name;
  notImplemented();
  return path;
}

bool deleteEmptyDirectory(const String&)
{
    notImplemented();
    return false;
}

bool getFileSize(const String&, long long& result)
{
    notImplemented();
    return false;
}

bool getFileModificationTime(const String&, time_t& result)
{
    notImplemented();
    return false;
}


Vector<String> listDirectory(const String& path, const String& filter)
{
    notImplemented();
}

} // namespace WebCore

