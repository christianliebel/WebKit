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

#ifndef QPOINT_H_
#define QPOINT_H_

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <KWQDef.h>

#include "qarray.h"

// class QPoint ================================================================

class QPoint {
public:

    // typedefs ----------------------------------------------------------------
    // enums -------------------------------------------------------------------
    // constants ---------------------------------------------------------------
    // static member functions -------------------------------------------------

    // constructors, copy constructors, and destructors ------------------------

    QPoint();
    QPoint(int, int);
    QPoint(const QPoint &);

// add no-op destructor
#ifdef _KWQ_PEDANTIC_
    ~QPoint() {}
#endif

    // member functions --------------------------------------------------------

    int x() const;
    int y() const;

    int manhattanLength() const;

    // operators ---------------------------------------------------------------

    QPoint &operator=(const QPoint &);
    
    friend QPoint operator+(const QPoint &, const QPoint &);
    friend QPoint operator-(const QPoint &, const QPoint &);

// protected -------------------------------------------------------------------
// private ---------------------------------------------------------------------

}; // class QPoint =============================================================


// class QPointArray ===========================================================

class QPointArray : public QArray<QPoint> {
public:

    // typedefs ----------------------------------------------------------------
    // enums -------------------------------------------------------------------
    // constants ---------------------------------------------------------------
    // static member functions -------------------------------------------------
    // constructors, copy constructors, and destructors ------------------------

    QPointArray(int);
    QPointArray(const QPointArray &);
    QPointArray(int, const QCOORD *);
    ~QPointArray();

    // member functions --------------------------------------------------------

    void setPoint(uint, int, int);
    bool setPoints(int, int, int, ...);

    // operators ---------------------------------------------------------------

    QPointArray &operator=(const QPointArray &);

// protected -------------------------------------------------------------------
// private ---------------------------------------------------------------------

}; // class QPointArray ========================================================

#endif
