/*
 *  Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies)
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "config.h"
#include "JSMimeTypeArray.h"

#include "AtomicString.h"
#include "MimeTypeArray.h"

namespace WebCore {

using namespace JSC;

bool JSMimeTypeArray::canGetItemsForName(ExecState*, MimeTypeArray* mimeTypeArray, const Identifier& propertyName)
{
    return mimeTypeArray->canGetItemsForName(propertyName);
}

JSValuePtr JSMimeTypeArray::nameGetter(ExecState* exec, const Identifier& propertyName, const PropertySlot& slot)
{
    JSMimeTypeArray* thisObj = static_cast<JSMimeTypeArray*>(slot.slotBase());
    return toJS(exec, thisObj->impl()->nameGetter(propertyName));
}

}
