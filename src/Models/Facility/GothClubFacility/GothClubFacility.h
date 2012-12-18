// GothClubFacility.h
#ifndef _GOTHCLUBFACILITY_H
#define _GOTHCLUBFACILITY_H

#include "Logger.h"
#include "FacilityModel.h"
#include "QueryEngine.h"
#include "ResourceBuff.h"

class GothClubFacility : public FacilityModel  {
/* --------------------
 * all MODEL classes have these members
 * --------------------
 */
 public:
  GothClubFacility();
  virtual ~GothClubFacility();
  virtual void initModuleMembers(QueryEngine* qe);
  virtual std::string str();
  virtual void cloneModuleMembersFrom(FacilityModel* src);
  virtual std::vector<rsrc_ptr> removeResource(Transaction order);
  virtual void addResource(Transaction trans,
                              std::vector<rsrc_ptr> manifest);

 public:
  virtual void receiveMessage(msg_ptr msg);

 public:
  virtual void handleTick(int time);
  virtual void handleTock(int time);
  double incommodity_;
  double outcommodity_;
  int capacity_;

  ResourceBuff bodies_;
  vector<msg_ptr> order_queue_;

};

#endif

