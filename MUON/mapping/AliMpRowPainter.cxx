/**************************************************************************
 * Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 *                                                                        *
 * Author: The ALICE Off-line Project.                                    *
 * Contributors are mentioned in the code where appropriate.              *
 *                                                                        *
 * Permission to use, copy, modify and distribute this software and its   *
 * documentation strictly for non-commercial purposes is hereby granted   *
 * without fee, provided that the above copyright notice appears in all   *
 * copies and that both the copyright notice and this permission notice   *
 * appear in the supporting documentation. The authors make no claims     *
 * about the suitability of this software for any purpose. It is          *
 * provided "as is" without express or implied warranty.                  *
 **************************************************************************/

// $Id$
// $MpId: AliMpRowPainter.cxx,v 1.7 2006/03/17 11:35:29 ivana Exp $
// Category: graphics
//
// Class AliMpRowPainter
// ---------------------
// Class for drawing a row into canvas
// Included in AliRoot: 2003/05/02
// Authors: David Guez, IPN Orsay
  
#include "AliMpRowPainter.h"
#include "AliMpGraphContext.h"
#include "AliMpRow.h"
#include "AliMpRowSegment.h"

#include <TVirtualX.h>
#include <TPad.h>
 
ClassImp(AliMpRowPainter)

//_______________________________________________________________________
AliMpRowPainter::AliMpRowPainter()
  : AliMpVPainter(),
    fRow(0)
{
  /// Default constructor
}

//_______________________________________________________________________
AliMpRowPainter::AliMpRowPainter(AliMpRow *row)
  : AliMpVPainter(),
    fRow(row)
{
  /// Standard constructor 
}

//_____________________________________________________________________________
AliMpRowPainter::AliMpRowPainter(const AliMpRowPainter& right) 
  : AliMpVPainter(right) {
// 
  /// Protected copy constructor (not provided)

  Fatal("AliMpRowPainter", "Copy constructor not provided.");
}

//_______________________________________________________________________
AliMpRowPainter::~AliMpRowPainter()
{
  /// Destructor
}

//_____________________________________________________________________________
AliMpRowPainter& AliMpRowPainter::operator=(const AliMpRowPainter& right)
{
  /// Assignment operator (not provided)

  // check assignment to self
  if (this == &right) return *this;

  Fatal("operator =", "Assignment operator not provided.");
    
  return *this;  
}    

//_______________________________________________________________________
void AliMpRowPainter::DumpObject()
{
/// Draw the owned object

  fRow->Dump();
}

//_______________________________________________________________________
TVector2 AliMpRowPainter::GetPosition() const
{
/// Get the owned object's position

  return fRow->Position();
}

//_______________________________________________________________________
TVector2 AliMpRowPainter::GetDimensions() const
{
/// Get the owned object's dimensions

  return fRow->Dimensions();
}

//_______________________________________________________________________
void AliMpRowPainter::Draw(Option_t *option)
{
/// Draw the sector on the current pad
/// The first letter of <option> is treated as follows:
/// - case "S" : each row segments are drawn separately
/// - case ""  : the whole row is drawn at once
/// in both cases, the rest of the option is passed
/// as argument to the Draw function of respectively
/// zone or row objects.

  AliMpGraphContext *gr = AliMpGraphContext::Instance();
  if( !fRow) return;

  gr->Push();
  InitGraphContext();

  switch (option[0]){
  case 'S':
    {
      for (Int_t iRowSeg=0;iRowSeg<fRow->GetNofRowSegments();++iRowSeg){
	AliMpVRowSegment *rowSegment = fRow->GetRowSegment(iRowSeg);
	gr->Push();

	gr->SetPadPosForReal(rowSegment->Position(),rowSegment->Dimensions());
	DrawObject(rowSegment,option+1);
      
	gr->Pop();
      }
    }
    break;
  default: AppendPad(option);
  }
  gr->Pop();
}

//_______________________________________________________________________
void AliMpRowPainter::Paint(Option_t *option)
{
  /// Paint the object

  AliMpGraphContext *gr = AliMpGraphContext::Instance();
  if( !fRow) return;
  Int_t col=gVirtualX->GetFillColor();
  gr->Push();
  gPad->Range(0.,0.,1.,1.);
  InitGraphContext();  
  PaintWholeBox(kTRUE);

  if (option[0]=='T'){
    Float_t textSize =   gVirtualX->GetTextSize();
    gVirtualX->SetTextSize(12);
    gPad->PaintText(GetPadPosition().X()-0.01,GetPadPosition().Y()-0.01,
		    Form("%d",fRow->GetID()));
    gVirtualX->SetTextSize(textSize);
  }


  gr->Pop();
  gVirtualX->SetFillColor(col);
}
