/*
 Source File : Hummus
 
 
 Copyright 2013 Gal Kahana HummusJS
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 
 */
#include <node.h>
#include <v8.h>

#include "PDFWriterDriver.h"
#include "PDFPageDriver.h"
#include "PageContentContextDriver.h"
#include "FormXObjectDriver.h"
#include "XObjectContentContextDriver.h"
#include "ResourcesDictionaryDriver.h"
#include "UsedFontDriver.h"

using namespace v8;

Handle<Value> CreateWriter(const Arguments& args) {
    HandleScope scope;
    return scope.Close(PDFWriterDriver::NewInstance(args));
}

void HummusInit(Handle<Object> exports) {
    
    PDFWriterDriver::Init();
    PDFPageDriver::Init();
    PageContentContextDriver::Init();
    FormXObjectDriver::Init();
    XObjectContentContextDriver::Init();
    ResourcesDictionaryDriver::Init();
    UsedFontDriver::Init();
    
    // createWriter will create a new pdfwriter, pass a string for the target path
    exports->Set(String::NewSymbol("createWriter"),FunctionTemplate::New(CreateWriter)->GetFunction());
}

NODE_MODULE(Hummus, HummusInit)