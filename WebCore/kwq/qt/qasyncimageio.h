/*
 * Copyright (C) 2001 Apple Computer, Inc.  All rights reserved.
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

#ifndef QASYNCIMAGEIO_H_
#define QASYNCIMAGEIO_H_

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

// for memset
#include <string.h> 

#include <KWQDef.h>

#include "qimage.h"
#include "qcolor.h"
#include "qrect.h"

// =============================================================================
// class QImageConsumer

class QImageConsumer {
public:

    // typedefs ----------------------------------------------------------------
    // enums -------------------------------------------------------------------
    // constants ---------------------------------------------------------------
    
    // static member functions -------------------------------------------------

    static const char* formatName(const uchar* buffer, int length);

    // constructors, copy constructors, and destructors ------------------------
    
// add no-arg constructor
#ifdef _KWQ_PEDANTIC_
    QImageConsumer() {}
#endif

// add no-op destructor
#ifdef _KWQ_PEDANTIC_
    ~QImageConsumer() {}
#endif
    
    // member functions --------------------------------------------------------

    virtual void changed(const QRect &)=0;
    virtual void end()=0;
    virtual void setSize(int,int)=0;
    
    // operators ---------------------------------------------------------------

// protected -------------------------------------------------------------------
// private ---------------------------------------------------------------------

private:

// add copy constructor
// this private declaration prevents copying
#ifdef _KWQ_PEDANTIC_
    QImageConsumer(const QImageConsumer &);
#endif

// add assignment operator 
// this private declaration prevents assignment
#ifdef _KWQ_PEDANTIC_
    QImageConsumer &operator=(const QImageConsumer &);
#endif

}; // end class QImageConsumer

// =============================================================================

// =============================================================================
// class QImageDecoder

class QImageDecoder {
public:

    // typedefs ----------------------------------------------------------------
    // enums -------------------------------------------------------------------
    // constants ---------------------------------------------------------------
    
    // static member functions -------------------------------------------------

    static const char* formatName(const uchar* buffer, int length);

    // constructors, copy constructors, and destructors ------------------------
    
// add no-arg constructor
#ifdef _KWQ_PEDANTIC_
    QImageDecoder() {}
#endif

    QImageDecoder(QImageConsumer *);
    ~QImageDecoder();
    
    // member functions --------------------------------------------------------
    // operators ---------------------------------------------------------------

// protected -------------------------------------------------------------------
// private ---------------------------------------------------------------------

private:

// add copy constructor
// this private declaration prevents copying
#ifdef _KWQ_PEDANTIC_
    QImageDecoder(const QImageDecoder &);
#endif

// add assignment operator 
// this private declaration prevents assignment
#ifdef _KWQ_PEDANTIC_
    QImageDecoder &operator=(const QImageDecoder &);
#endif

}; // end class QImageDecoder

// =============================================================================

// =============================================================================
// class QImageFormat

class QImageFormat {
public:

    // typedefs ----------------------------------------------------------------
    // enums -------------------------------------------------------------------
    // constants ---------------------------------------------------------------
    // static member functions -------------------------------------------------

    // constructors, copy constructors, and destructors ------------------------
    
// add no-arg constructor
#ifdef _KWQ_PEDANTIC_
    QImageFormat() {}
#endif

    virtual ~QImageFormat();
    
    // member functions --------------------------------------------------------

    virtual int decode(QImage &, QImageConsumer *, const uchar *, int) = 0;
    
    // operators ---------------------------------------------------------------

// protected -------------------------------------------------------------------
// private ---------------------------------------------------------------------

private:

// add copy constructor
// this private declaration prevents copying
#ifdef _KWQ_PEDANTIC_
    QImageFormat(const QImageFormat &);
#endif

// add assignment operator 
// this private declaration prevents assignment
#ifdef _KWQ_PEDANTIC_
    QImageFormat &operator=(const QImageFormat &);
#endif

}; // end class QImageFormat

// =============================================================================

// =============================================================================
// class QImageFormatType

class QImageFormatType {
public:

    // typedefs ----------------------------------------------------------------
    // enums -------------------------------------------------------------------
    // constants ---------------------------------------------------------------
    // static member functions -------------------------------------------------

    // constructors, copy constructors, and destructors ------------------------
    
// add no-arg constructor
#ifdef _KWQ_PEDANTIC_
    QImageFormatType() {}
#endif

    virtual ~QImageFormatType();
    
    // member functions --------------------------------------------------------

    virtual QImageFormat *decoderFor(const uchar *, int)=0;
    
    // operators ---------------------------------------------------------------

// protected -------------------------------------------------------------------
// private ---------------------------------------------------------------------

private:

// add copy constructor
// this private declaration prevents copying
#ifdef _KWQ_PEDANTIC_
    QImageFormatType(const QImageFormatType &);
#endif

// add assignment operator 
// this private declaration prevents assignment
#ifdef _KWQ_PEDANTIC_
    QImageFormatType &operator=(const QImageFormatType &);
#endif

}; // end class QImageFormatType

// =============================================================================

#endif
