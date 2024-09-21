/*
   Source File : LinearGradientShadingPatternWritingTask.cpp


   Copyright 2011 Gal Kahana PDFWriter

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


#include "LinearGradientShadingPatternWritingTask.h"
#include "ShadingWriter.h"

using namespace PDFHummus;

LinearGradientShadingPatternWritingTask::LinearGradientShadingPatternWritingTask(
    double inX0,
    double inY0,
    double inX1,
    double inY1,
    InterpretedGradientStopList inColorLine,
    FT_PaintExtend inGradientExtend,
    PDFRectangle inBounds,
    PDFMatrix inMatrix,
    ObjectIDType inPatternObjectId
) {
   x0 = inX0;
   y0 = inY0;
   x1 = inX1;
   y1 = inY1;
   mColorLine = inColorLine;
   mGradientExtend = inGradientExtend;
   mBounds = inBounds;
   mMatrix = inMatrix;
   mPatternObjectId = inPatternObjectId;   
}

LinearGradientShadingPatternWritingTask::~LinearGradientShadingPatternWritingTask(){
}

EStatusCode LinearGradientShadingPatternWritingTask::Write(
    ObjectsContext* inObjectsContext,
    DocumentContext* inDocumentContext) {

    ShadingWriter shadingWriter(inObjectsContext, inDocumentContext);

    return shadingWriter.WriteLinearShadingPatternObject(
        x0,
        y0,
        x1,
        y1,
        mColorLine,
        mGradientExtend,
        mBounds,
        mMatrix,
        mPatternObjectId
    );
}