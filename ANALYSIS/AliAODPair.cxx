#include "AliAODPair.h"
//_________________________________________________________________________
///////////////////////////////////////////////////////////////////////////
//
// class AliAODPair
//
// class implements pair of particles and taking care of caluclation (almost)
// all of pair properties (Qinv, InvMass,...)
// 
// more info: http://alisoft.cern.ch/people/skowron/analyzer/index.html
//
////////////////////////////////////////////////////////////////////////////

#include "AliVAODParticle.h"
#include "AliTrackPoints.h"

ClassImp(AliAODPair)

/************************************************************************/
AliAODPair::AliAODPair(Bool_t rev):
 fPart1(0x0),
 fPart2(0x0),
 fSwappedPair(0x0),
 fQSideLCMS(0.0),
 fQSideLCMSNotCalc(kTRUE),
 fQOutLCMS(0.0),
 fQOutLCMSNotCalc(kTRUE),
 fQLongLCMS(0.0),
 fQLongLCMSNotCalc(kTRUE),
 fQInv(0.0),
 fQInvNotCalc(kTRUE),
 fInvMass(0.0),
 fInvMassNotCalc(kTRUE),
 fKt(0.0),
 fKtNotCalc(kTRUE),
 fKStar(0.0),
 fKStarNotCalc(kTRUE),
 fPInv(0.0),
 fQSide(0.0),
 fOut(0.0),
 fQLong(0.0),
 fMt(0.0),
 fMtNotCalc(kTRUE),
 fInvMassSqr(0.0),
 fMassSqrNotCalc(kTRUE),
 fQInvL(0.0),
 fQInvLNotCalc(kTRUE),
 fAvarageDistance(0.0),
 fAvarageDistanceNotCalc(kTRUE),
 fPxSum(0.0),
 fPySum(0.0),
 fPzSum(0.0),
 fESum(0.0),
 fSumsNotCalc(kTRUE),
 fPxDiff(0.0),
 fPyDiff(0.0),
 fPzDiff(0.0),
 fEDiff(0.0),
 fDiffsNotCalc(kTRUE),
 fGammaLCMS(0.0),
 fGammaLCMSNotCalc(kTRUE),
 fChanged(kTRUE)
 {
//value of rev defines if it is Swapped
//if you pass kTRUE swpaped pair will NOT be created
//though you wont be able to get the swaped pair from this pair

  if(!rev) fSwappedPair = new AliAODPair(kTRUE); //if false create swaped pair
  
 }
/************************************************************************/

AliAODPair::AliAODPair(AliVAODParticle* part1, AliVAODParticle* part2, Bool_t rev):
 fPart1(part1),
 fPart2(part2),
 fSwappedPair(0x0),
 fQSideLCMS(0.0),
 fQSideLCMSNotCalc(kTRUE),
 fQOutLCMS(0.0),
 fQOutLCMSNotCalc(kTRUE),
 fQLongLCMS(0.0),
 fQLongLCMSNotCalc(kTRUE),
 fQInv(0.0),
 fQInvNotCalc(kTRUE),
 fInvMass(0.0),
 fInvMassNotCalc(kTRUE),
 fKt(0.0),
 fKtNotCalc(kTRUE),
 fKStar(0.0),
 fKStarNotCalc(kTRUE),
 fPInv(0.0),
 fQSide(0.0),
 fOut(0.0),
 fQLong(0.0),
 fMt(0.0),
 fMtNotCalc(kTRUE),
 fInvMassSqr(0.0),
 fMassSqrNotCalc(kTRUE),
 fQInvL(0.0),
 fQInvLNotCalc(kTRUE),
 fAvarageDistance(0.0),
 fAvarageDistanceNotCalc(kTRUE),
 fPxSum(0.0),
 fPySum(0.0),
 fPzSum(0.0),
 fESum(0.0),
 fSumsNotCalc(kTRUE),
 fPxDiff(0.0),
 fPyDiff(0.0),
 fPzDiff(0.0),
 fEDiff(0.0),
 fDiffsNotCalc(kTRUE),
 fGammaLCMS(0.0),
 fGammaLCMSNotCalc(kTRUE),
 fChanged(kTRUE)
 {
//value of rev defines if it is Swapped
//if you pass kTRUE swpaped pair will NOT be created
//though you wont be able to get the swaped pair from this pair

  if(!rev) fSwappedPair = new AliAODPair(part2,part1,kTRUE); //if false create swaped pair
  
 }
/************************************************************************/
AliAODPair::AliAODPair(const AliAODPair& in):
 TObject(in),
 fPart1(0x0),
 fPart2(0x0),
 fSwappedPair(0x0),
 fQSideLCMS(0.0),
 fQSideLCMSNotCalc(kTRUE),
 fQOutLCMS(0.0),
 fQOutLCMSNotCalc(kTRUE),
 fQLongLCMS(0.0),
 fQLongLCMSNotCalc(kTRUE),
 fQInv(0.0),
 fQInvNotCalc(kTRUE),
 fInvMass(0.0),
 fInvMassNotCalc(kTRUE),
 fKt(0.0),
 fKtNotCalc(kTRUE),
 fKStar(0.0),
 fKStarNotCalc(kTRUE),
 fPInv(0.0),
 fQSide(0.0),
 fOut(0.0),
 fQLong(0.0),
 fMt(0.0),
 fMtNotCalc(kTRUE),
 fInvMassSqr(0.0),
 fMassSqrNotCalc(kTRUE),
 fQInvL(0.0),
 fQInvLNotCalc(kTRUE),
 fAvarageDistance(0.0),
 fAvarageDistanceNotCalc(kTRUE),
 fPxSum(0.0),
 fPySum(0.0),
 fPzSum(0.0),
 fESum(0.0),
 fSumsNotCalc(kTRUE),
 fPxDiff(0.0),
 fPyDiff(0.0),
 fPzDiff(0.0),
 fEDiff(0.0),
 fDiffsNotCalc(kTRUE),
 fGammaLCMS(0.0),
 fGammaLCMSNotCalc(kTRUE),
 fChanged(kTRUE)
{
 //cpy constructor
 in.Copy(*this);
}
/************************************************************************/

AliAODPair& AliAODPair::operator=(const AliAODPair& in)
{
 //Assigment operator
 in.Copy(*this);
 return *this;
}
/************************************************************************/

Double_t AliAODPair::GetInvMass()
{
//Returns qinv value for a pair
  if(fInvMassNotCalc)
   {
     CalculateInvMassSqr(); //method is inline so we not waste th time for jumping into method 
     
     if(fInvMassSqr<0)  fInvMass = TMath::Sqrt(-fInvMassSqr);
     else fInvMass = TMath::Sqrt(fInvMassSqr); 
     
     fInvMassNotCalc = kFALSE;
   }
  return fInvMass;
}
/************************************************************************/

Double_t AliAODPair::GetQSideLCMS()
{
//return Q Side in Central Of Mass System in Longitudialy Comoving Frame
 
  if (fQSideLCMSNotCalc)
   {
    fQSideLCMS = (fPart1->Px()*fPart2->Py()-fPart2->Px()*fPart1->Py())/GetKt();
    fQSideLCMSNotCalc = kFALSE;
   }
  return fQSideLCMS;
}
/************************************************************************/

Double_t AliAODPair::GetQOutLCMS()
{
 //caculates Qout in Center Of Mass Longitudionally Co-Moving
 if(fQOutLCMSNotCalc)
  {
   CalculateSums();
   CalculateDiffs();

   if (fPart1->Mass() != fPart2->Mass())
    {
/*    
      //STAR algorithm
      Double_t beta  = fPzSum/fESum;
      Double_t gamma = GetGammaToLCMS();
      Double_t el = gamma * (fPart1->E() - beta * fPart1->Pz());
      Double_t x  = ( fPart1->Px()*fPxSum + fPart1->Py()*fPySum) / ( 2.0*GetKt() );
      beta  = 2.0*GetKt()/GetMt();
      gamma = GetMt()/GetQInv();
      fQOutLCMS = gamma * (x - beta * el);
*/

      //beta=fPzSum/fESum;    // Longit. V == beta
      Double_t beta=fPzSum/fESum;
      Double_t gamma = GetGammaToLCMS();
      
      Double_t cosphi=fPxSum/(2.0*GetKt());  // cos(phi)
      Double_t sinphi=fPySum/(2.0*GetKt()); // sin(phi)
      
//      ROTATE(part1Px,part1Py,SPHI,CPHI,part1Px,part1Py);//ROT8
//      ROTATE(part2Px,part2Py,SPHI,CPHI,part2Px,part2Py);//ROT8
      Double_t tmp;
      tmp = fPart1->Px()*cosphi + fPart1->Py()*sinphi;
      Double_t part1Py = fPart1->Py()*cosphi - fPart1->Px()*sinphi;
      Double_t part1Px = tmp;

      tmp = fPart2->Px()*cosphi + fPart2->Py()*sinphi;
      Double_t part2Py = fPart2->Py()*cosphi - fPart2->Px()*sinphi;
      Double_t part2Px = tmp;
      
      
//      LTR(part1Pz,E1,beta,GetGammaToLCMS(),part1Pz,E1a);
//      LTR(part2Pz,E2,beta,GetGammaToLCMS(),part2Pz,E2a);
      Double_t part1Pz=gamma*(fPart1->Pz()-beta*fPart1->E());
      Double_t part2Pz=gamma*(fPart2->Pz()-beta*fPart2->E());

      Double_t part1P2=part1Px*part1Px+part1Py*part1Py+part1Pz*part1Pz;
      Double_t part2P2=part2Px*part2Px+part2Py*part2Py+part2Pz*part2Pz;
      Double_t part1E=TMath::Sqrt(fPart1->Mass()*fPart1->Mass()+part1P2);
      Double_t part2E=TMath::Sqrt(fPart2->Mass()*fPart2->Mass()+part2P2);
      Double_t sumE=part1E+part2E;
      Double_t sumPx=part1Px+part2Px;
      Double_t sumPy=part1Py+part2Py;
      Double_t sumPZ=part1Pz+part2Pz;
      Double_t sumP2=sumPx*sumPx+sumPy*sumPy+sumPZ*sumPZ;

      Double_t relmass=TMath::Sqrt(sumE*sumE-sumP2);
      Double_t hf = (fPart1->Mass()*fPart1->Mass() - fPart2->Mass()*fPart2->Mass())/(relmass*relmass);
      fQOutLCMS=(part1Px-part2Px);//== id
      fQOutLCMS=fQOutLCMS-sumPx*hf; //sumPx == fPxSum ale po rotacji i transf
    }
   else
    {
      Double_t k2 = fPxSum*fPxDiff+fPySum*fPyDiff;
      fQOutLCMS = 0.5*k2/GetKt();
   // if (non-id)  fQOutLCMS=fQOutLCMS - sumPx*HF;
    }

    
   fQOutLCMSNotCalc = kFALSE;
  }
 return fQOutLCMS;
}
/************************************************************************/

Double_t AliAODPair::GetQLongLCMS()
{
 //return Q Long in Central Of Mass System in Longitudialy Comoving Frame
 if (fQLongLCMSNotCalc)
  {
    CalculateSums();
    CalculateDiffs();
    Double_t beta = fPzSum/fESum;
    fQLongLCMS = GetGammaToLCMS() * ( fPzDiff - beta*fEDiff );
    fQLongLCMSNotCalc = kFALSE;
  }
 return fQLongLCMS; 
}
/************************************************************************/

Double_t AliAODPair::GetKt()
{
 //calculates the evarage momentum of the pair
  if(fKtNotCalc)
   { 
     CalculateSums();
     fKt =  0.5*TMath::Hypot(fPxSum,fPySum);
     fKtNotCalc = kFALSE;
   }
  return fKt;
}
/************************************************************************/

Double_t AliAODPair::GetKStar()
{
  //calculates invariant velocity difference
  if (fKStarNotCalc)
   { 
    CalculateSums();

    Double_t ptrans = fPxSum*fPxSum + fPySum*fPySum;
    Double_t mtrans = fESum*fESum - fPzSum*fPzSum;
    if (ptrans > mtrans)
     {
       Error("GetKStar","Tranverse momentum bigger than transverse mass. Not normal for on-shell particles");
       Error("GetKStar","Particle1:");
       fPart1->Print();
       Error("GetKStar","Particle2:");
       fPart2->Print();
       Error("GetKStar","");
       
       fKStar = 10e5;
       fKStarNotCalc = kFALSE;
       return fKStar;
     }
    Double_t pinv =   TMath::Sqrt(mtrans - ptrans);

    Double_t q = (fPart1->Mass()*fPart1->Mass() - fPart2->Mass()*fPart2->Mass())/pinv;
    
    CalculateQInvL();
    
    q = q*q - fQInvL;
    if ( q < 0)
     {
       Info("GetKStar","Sqrt of negative number q = %f",q);
       Error("GetKStar","Particle1:");
       fPart1->Print();
       Error("GetKStar","Particle2:");
       fPart2->Print();
       fKStar = 10e5;
       fKStarNotCalc = kFALSE;
       return fKStar;
     }
     
    q = TMath::Sqrt(q);
    fKStar = q/2.;
    fKStarNotCalc = kFALSE;
   }
  return fKStar;
}
/************************************************************************/

Double_t AliAODPair::GetQInv()
{
//returns Qinv 
//warning for non-id particles you want to use 2*KStar
  if(fQInvNotCalc)
   {
    CalculateQInvL();
    fQInv = TMath::Sqrt(TMath::Abs(fQInvL));
    fQInvNotCalc = kFALSE;
   }
  return fQInv;
}
/************************************************************************/

Double_t AliAODPair::GetGammaToLCMS()
{
  //calculates gamma factor of the boost to LCMS
  if(fGammaLCMSNotCalc)
   {
     CalculateSums();
     Double_t beta = fPzSum/fESum;
     fGammaLCMS = 1.0/TMath::Sqrt(1.0 - beta*beta);
     fGammaLCMSNotCalc = kFALSE;
   }
  return fGammaLCMS;
}
/************************************************************************/

Double_t AliAODPair::GetMt()
{
  //Calculates transverse mass of the pair
  if (fMtNotCalc)
   {
     CalculateSums();
     fMt = TMath::Sqrt(fESum*fESum - fPzSum*fPzSum);
     fMtNotCalc = kFALSE;
   }
   return fMt;
}
/************************************************************************/

Double_t AliAODPair::GetAvarageDistance()
{
//returns and buffers avarage distance between two tracks calculated 
// out of track points (see AliAODTrackPoints class)

  if (fAvarageDistanceNotCalc)
   {
     fAvarageDistance = AvDistance();
     fAvarageDistanceNotCalc = kFALSE;
   }
  return fAvarageDistance;
}
/************************************************************************/

Double_t AliAODPair::AvDistance()
{
  //returns avarage distance between two tracks in range 
  //as defined in Track-Points of AliVAODParticle
  //returns negative value if error uccured f.g. tracks do not have track-points
  AliTrackPoints* tpts1 = fPart1->GetTPCTrackPoints();
  if ( tpts1 == 0x0)
   {//it could be simulated pair
//     Warning("GetValue","Track 1 does not have Track Points. Pair NOT Passed.");
     return -1.0;
   }

  AliTrackPoints* tpts2 = fPart2->GetTPCTrackPoints();
  if ( tpts2 == 0x0)
   {
//     Warning("GetValue","Track 2 does not have Track Points. Pair NOT Passed.");
     return -1.0;
   }

  return tpts1->AvarageDistance(*tpts2);
}
