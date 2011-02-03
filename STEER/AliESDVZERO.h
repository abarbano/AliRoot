#ifndef ALIESDVZERO_H
#define ALIESDVZERO_H

//-------------------------------------------------------------------------
//     Container class for ESD VZERO data
//     Author: Brigitte Cheynis & Cvetan Cheshkov
//-------------------------------------------------------------------------

#include <AliVVZERO.h>

class AliESDVZERO : public AliVVZERO 
{
public:
  AliESDVZERO();
  AliESDVZERO(const AliESDVZERO&o);
  AliESDVZERO(UInt_t BBtriggerV0A,   UInt_t BGtriggerV0A,
	      UInt_t BBtriggerV0C,   UInt_t BGtriggerV0C,
	      Float_t *Multiplicity, Float_t *Adc, 
	      Float_t *Time, Float_t *Width, Bool_t *BBFlag, Bool_t *BGFlag);
  void Copy(TObject &obj) const;

  virtual ~AliESDVZERO() {};

  // Setters
  void SetBBtriggerV0A(UInt_t BBtrigger) {fBBtriggerV0A=BBtrigger;}
  void SetBGtriggerV0A(UInt_t BGtrigger) {fBGtriggerV0A=BGtrigger;}
  void SetBBtriggerV0C(UInt_t BBtrigger) {fBBtriggerV0C=BBtrigger;}
  void SetBGtriggerV0C(UInt_t BGtrigger) {fBGtriggerV0C=BGtrigger;}
  void SetMultiplicity(Float_t Multiplicity[64])
    {for(Int_t i=0;i<64;i++) fMultiplicity[i]=Multiplicity[i];}
  void SetADC(Float_t adc[64])
    {for(Int_t i=0;i<64;i++) fAdc[i]=adc[i];}
  void SetTime(Float_t time[64])
    {for(Int_t i=0;i<64;i++) fTime[i]=time[i];}
  void SetWidth(Float_t width[64])
    {for(Int_t i=0;i<64;i++) fWidth[i]=width[i];}    
  void SetBBFlag(Bool_t BBFlag[64])
    {for(Int_t i=0;i<64;i++) fBBFlag[i]=BBFlag[i];} 
  void SetBGFlag(Bool_t BGFlag[64])
    {for(Int_t i=0;i<64;i++) fBGFlag[i]=BGFlag[i];}   

  void SetV0ATime(Float_t time) {fV0ATime = time;}
  void SetV0CTime(Float_t time) {fV0CTime = time;}
  void SetV0ATimeError(Float_t err) {fV0ATimeError = err;}
  void SetV0CTimeError(Float_t err) {fV0CTimeError = err;}

  void SetV0ADecision(Decision des) {fV0ADecision = des;}
  void SetV0CDecision(Decision des) {fV0CDecision = des;}
         
  // Getters  
  virtual Short_t  GetNbPMV0A() const;
  virtual Short_t  GetNbPMV0C() const;
  virtual Float_t  GetMTotV0A() const;
  virtual Float_t  GetMTotV0C() const; 
  virtual Float_t  GetMRingV0A(Int_t ring) const;
  virtual Float_t  GetMRingV0C(Int_t ring) const;

  virtual Float_t  GetMultiplicity(Int_t i) const;
  virtual Float_t  GetMultiplicityV0A(Int_t i) const;
  virtual Float_t  GetMultiplicityV0C(Int_t i) const;    
  virtual Float_t  GetAdc(Int_t i) const;
  virtual Float_t  GetAdcV0A(Int_t i) const; 
  virtual Float_t  GetAdcV0C(Int_t i) const;   
  virtual Float_t  GetTime(Int_t i) const;
  virtual Float_t  GetTimeV0A(Int_t i) const;   
  virtual Float_t  GetTimeV0C(Int_t i) const;    
  virtual Float_t  GetWidth(Int_t i) const;
  virtual Float_t  GetWidthV0A(Int_t i) const;
  virtual Float_t  GetWidthV0C(Int_t i) const;
  virtual Bool_t   BBTriggerV0A(Int_t i) const;
  virtual Bool_t   BGTriggerV0A(Int_t i) const;
  virtual Bool_t   BBTriggerV0C(Int_t i) const;
  virtual Bool_t   BGTriggerV0C(Int_t i) const;  
  virtual Bool_t   GetBBFlag(Int_t i) const;
  virtual Bool_t   GetBGFlag(Int_t i) const;

  virtual Float_t  GetV0ATime() const { return fV0ATime; }
  virtual Float_t  GetV0CTime() const { return fV0CTime; }
  virtual Float_t  GetV0ATimeError() const { return fV0ATimeError; }
  virtual Float_t  GetV0CTimeError() const { return fV0CTimeError; }

  virtual Decision GetV0ADecision() const { return fV0ADecision; }
  virtual Decision GetV0CDecision() const { return fV0CDecision; }
  
  AliESDVZERO &operator=(const AliESDVZERO& source);
    
protected:

  UInt_t  fBBtriggerV0A;     // bit mask for Beam-Beam trigger in V0A
  UInt_t  fBGtriggerV0A;     // bit mask for Beam-Gas trigger in V0A
  UInt_t  fBBtriggerV0C;     // bit mask for Beam-Beam trigger in V0C
  UInt_t  fBGtriggerV0C;     // bit mask for Beam-Gas trigger in V0C

  Float_t fMultiplicity[64]; //  multiplicity for each channel
  Float_t fAdc[64];          //  adc for each channel
  Float_t fTime[64];         //  time for each channel
  Float_t fWidth[64];        //  time width for each channel
  Bool_t  fBBFlag[64];       //  BB Flags from Online V0 Electronics
  Bool_t  fBGFlag[64];       //  BG Flags from Online V0 Electronics

  Float_t fV0ATime;          // Average time in V0A
  Float_t fV0CTime;          // Average time in V0C
  Float_t fV0ATimeError;     // Error in the average time in V0A
  Float_t fV0CTimeError;     // Error in the average time in V0C

  Decision fV0ADecision;     // V0A final decision based on average time of channels
  Decision fV0CDecision;     // V0C final decision based on average time of channels

  ClassDef(AliESDVZERO,9)
};

#endif
