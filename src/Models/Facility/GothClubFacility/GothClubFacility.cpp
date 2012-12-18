// GothClubFacility.cpp
// Implements the GothClubFacility class

#include "GothClubFacility.h"

#include "Logger.h"
#include "CycException.h"

using namespace std;
using namespace boost;

/* --------------------
 * all MODEL classes have these members
 * --------------------
 */

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
GothClubFacility::GothClubFacility() {};

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
GothClubFacility::~GothClubFacility() {};

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -    
void GothClubFacility::initModuleMembers(QueryEngine* qe) {
  QueryEngine* input = qe->queryElement("input");
  //retrieve input data members here. For example :  
  incommodity_ = lexical_cast<string>(input -> getElementContent("incommodity"));
  outcommodity_ = lexical_cast<string>(input -> getElementContent("outcommodity"));
  capacity_ = lexical_cast<int>(input -> getElementContent("capacity"));
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -    
void GothClubFacility::cloneModuleMembersFrom(FacilityModel* src) {
  GothClubFacility* src_fac = dynamic_cast<GothClubFacility*>(src);
  //copy data members here. For example : 
  incommodity_ = src_fac->incommodity_;
  outcommodity_ = src_fac->outcommodity_;
  capacity_ = src_fac->capacity_;
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -    
std::string GothClubFacility::str() {
  return "I am so metal!\n";
};

/* ------------------- */ 


/* --------------------
 * all COMMUNICATOR classes have these members
 * --------------------
 */

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void GothClubFacility::receiveMessage(msg_ptr msg) {
  order_queue_.push_back(msg);
};

/* ------------------- */ 


/* --------------------
 * all FACILITYMODEL classes have these members
 * --------------------
 */

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
vector<rsrc_ptr> GothClubFacility::removeResource(Transaction trans) {
  if (trans.commod() != outcommodity_) {
    string err_msg = "GothClubFacility can only send '" + outcommodity_  + ".";
    throw CycException(err_msg);
  }

  Manifest bods = bodies_.popNum(1);
  return bods;
}
    
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void GothClubFacility::addResource(Transaction trans, std::vector<rsrc_ptr> manifest){
bodies_.pushAll(manifest);
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void GothClubFacility::handleTick(int time){}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void GothClubFacility::handleTock(int time){}

/* ------------------- */ 


/* --------------------
 * all MODEL classes have these members
 * --------------------
 */

extern "C" Model* constructGothClubFacility() {
  return new GothClubFacility();
}

extern "C" void destructGothClubFacility(Model* model) {
  delete model;
}

/* ------------------- */ 

