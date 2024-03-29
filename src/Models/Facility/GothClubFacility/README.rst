GothClubFacility
=============

This is a directory intended to hold FacilityModel templates. 

That is, it is intended to hold the skeletal stub modules for assistance with 
developing new concrete FacilityModels for Cyclus. It also holds elements of a build 
siestem that facilitates building and installation in tandem with the Cyclus 
building and installation process. 

More information on facilities can be found `here <http://cyclus.github.com/devdoc/make-models/facility.html/>`_.

What's in this directory?
=========================
- **CMakeLists.txt**, a file directing the build for this directory
- **GothClubFacility.cpp**, a skeletal FacilityModel concrete instance, a template for 
  implementing the expected interface for Facilitys 
- **GothClubFacility.h**, a skeletal header file template that defines the
  expected interface for Facilitys 
- **GothClubFacilityTests.cpp**, a file implementing test templates for the GothClubFacility
- **GothClubFacilityInput.xml**, an example input file utilizing the GothClubFacility
- **GothClubFacility.rng**, a relaxng schema for defining the input parameters of the 
  GothClubFacility
