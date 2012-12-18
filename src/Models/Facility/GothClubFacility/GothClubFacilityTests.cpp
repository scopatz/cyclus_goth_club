// GothClubFacilityTests.cpp
#include <gtest/gtest.h>

#include "GothClubFacility.h"
#include "CycException.h"
#include "Message.h"
#include "FacilityModelTests.h"
#include "ModelTests.h"

#include <string>
#include <queue>

using namespace std;

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
class FakeGothClubFacility : public GothClubFacility {
  public:
    FakeGothClubFacility() : GothClubFacility() {
    }

    virtual ~FakeGothClubFacility() {
    }
};

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Model* GothClubFacilityModelConstructor(){
  return dynamic_cast<Model*>(new FakeGothClubFacility());
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
FacilityModel* GothClubFacilityConstructor(){
  return dynamic_cast<FacilityModel*>(new FakeGothClubFacility());
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
class GothClubFacilityTest : public ::testing::Test {
  protected:
    FakeGothClubFacility* src_facility;
    FakeGothClubFacility* new_facility; 

    virtual void SetUp(){
      src_facility = new FakeGothClubFacility();
      src_facility->setParent(new TestInst());
      new_facility = new FakeGothClubFacility();
      // for facilities that trade commodities, create appropriate markets here
    };

    virtual void TearDown() {
      delete src_facility;
      delete new_facility;
      // for facilities that trade commodities, delete appropriate markets here
    }
};


//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
TEST_F(GothClubFacilityTest, InitialState) {
  // Test things about the initial state of the facility here
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
TEST_F(GothClubFacilityTest, CopyFreshModel) {
  new_facility->cloneModuleMembersFrom(src_facility); // deep copy
  EXPECT_NO_THROW(dynamic_cast<GothClubFacility*>(new_facility)); // still a stub facility
  EXPECT_NO_THROW(dynamic_cast<FakeGothClubFacility*>(new_facility)); // still a fake stub facility
  // Test that GothClubFacility specific parameters are initialized in the deep copy method here
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
TEST_F(GothClubFacilityTest, Print) {
  EXPECT_NO_THROW(std::string s = src_facility->str());
  // Test GothClubFacility specific aspects of the print method here
}


//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
TEST_F(GothClubFacilityTest, ReceiveMessage) {
  msg_ptr msg;
  // Test GothClubFacility specific behaviors of the receiveMessage function here
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
TEST_F(GothClubFacilityTest, Tick) {
  int time = 1;
  EXPECT_NO_THROW(src_facility->handleTick(time));
  // Test GothClubFacility specific behaviors of the handleTick function here
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
TEST_F(GothClubFacilityTest, Tock) {
  int time = 1;
  EXPECT_NO_THROW(src_facility->handleTick(time));
  // Test GothClubFacility specific behaviors of the handleTock function here
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
INSTANTIATE_TEST_CASE_P(GothClubFac, FacilityModelTests, Values(&GothClubFacilityConstructor));
INSTANTIATE_TEST_CASE_P(GothClubFac, ModelTests, Values(&GothClubFacilityModelConstructor));

