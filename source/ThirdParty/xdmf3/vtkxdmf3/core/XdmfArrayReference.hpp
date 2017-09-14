/*****************************************************************************/
/*                                    XDMF                                   */
/*                       eXtensible Data Model and Format                    */
/*                                                                           */
/*  Id : XdmfArrayReference.hpp                                              */
/*                                                                           */
/*  Author:                                                                  */
/*     Andrew Burns                                                          */
/*     andrew.j.burns2@us.army.mil                                           */
/*     US Army Research Laboratory                                           */
/*     Aberdeen Proving Ground, MD                                           */
/*                                                                           */
/*     Copyright @ 2013 US Army Research Laboratory                          */
/*     All Rights Reserved                                                   */
/*     See Copyright.txt for details                                         */
/*                                                                           */
/*     This software is distributed WITHOUT ANY WARRANTY; without            */
/*     even the implied warranty of MERCHANTABILITY or FITNESS               */
/*     FOR A PARTICULAR PURPOSE.  See the above copyright notice             */
/*     for more information.                                                 */
/*                                                                           */
/*****************************************************************************/

#ifndef XDMFARRAYREFERENCE_HPP_
#define XDMFARRAYREFERENCE_HPP_

// C Compatible Includes
#include "XdmfCore.hpp"
#include "XdmfArray.hpp"
#include "XdmfItem.hpp"

#ifdef __cplusplus

class XdmfArray;

/**
 * @brief Serves as a link between an array and one or more arrays containing data it pulls from.
 *
 * The Array Reference class provides the basic framework for the writing and
 * reading of the Function and Subset classes by allowing properties and tags
 * to be migrated to them.
 */
class XDMFCORE_EXPORT XdmfArrayReference : public XdmfItem {

public:

  virtual ~XdmfArrayReference();

  LOKI_DEFINE_VISITABLE(XdmfArrayReference, XdmfItem)

  /**
   * Gets the properties of the array that the reference will generate when read from file.
   *
   * Example of use:
   *
   * C++
   * 
   * @dontinclude ExampleXdmfFunction.cpp
   * @skipline //#initexpression
   * @until //#initexpression
   * @skipline //#setConstructedProperties
   * @until //#setConstructedProperties
   * @skipline //#getConstructedProperties
   * @until //#getConstructedProperties
   *
   * Python
   *
   * @dontinclude XdmfExampleFunction.py
   * @skipline #//initexpression
   * @until #//initexpression
   * @skipline #//setConstructedProperties
   * @until #//setConstructedProperties
   * @skipline #//getConstructedProperties
   * @until #//getConstructedProperties
   *
   * @return    The properties of the array to be generated
   */
  std::map<std::string, std::string> getConstructedProperties();

  /**
   * Gets the type of array that the reference will generate when read from file.
   *
   * Example of use:
   *
   * C++
   * 
   * @dontinclude ExampleXdmfFunction.cpp
   * @skipline //#initexpression
   * @until //#initexpression
   * @skipline //#setConstructedType
   * @until //#setConstructedType
   * @skipline //#getConstructedType
   * @until //#getConstructedType
   *
   * Python
   *
   * @dontinclude XdmfExampleFunction.py
   * @skipline #//initexpression
   * @until #//initexpression
   * @skipline #//setConstructedType
   * @until #//setConstructedType
   * @skipline #//getConstructedType
   * @until #//getConstructedType
   *
   * @return    The tag of the type to be generated
   */
  std::string getConstructedType() const;

  virtual std::map<std::string, std::string> getItemProperties() const;

  /**
   * Parses the reference and generates an array containing the values that
   * the reference produces.
   *
   * Example of use:
   *
   * C++
   * 
   * @dontinclude ExampleXdmfFunction.cpp
   * @skipline //#initexpression
   * @until //#initexpression
   * @skipline //#read
   * @until //#read
   *
   * Python
   *
   * @dontinclude XdmfExampleFunction.py
   * @skipline #//initexpression
   * @until #//initexpression
   * @skipline #//read
   * @until #//read
   *
   * @return    The array generated by the reference
   */
  virtual shared_ptr<XdmfArray> read() const = 0;

  /**
   * Sets the properties of array that the reference will generate when read from file.
   *
   * Example of use:
   *
   * C++
   * 
   * @dontinclude ExampleXdmfFunction.cpp
   * @skipline //#initexpression
   * @until //#initexpression
   * @skipline //#setConstructedProperties
   * @until //#setConstructedProperties
   *
   * Python
   *
   * @dontinclude XdmfExampleFunction.py
   * @skipline #//initexpression
   * @until #//initexpression
   * @skipline #//setConstructedProperties
   * @until #//setConstructedProperties
   *
   * @param     newProperties   The properties of the array to be generated
   */
  void
  setConstructedProperties(std::map<std::string, std::string> newProperties);

  /**
   * Sets the type of array that the reference will generate when read from file.
   *
   * Example of use:
   *
   * C++
   * 
   * @dontinclude ExampleXdmfFunction.cpp
   * @skipline //#initexpression
   * @until //#initexpression
   * @skipline //#setConstructedType
   * @until //#setConstructedType
   *
   * Python
   *
   * @dontinclude XdmfExampleFunction.py
   * @skipline #//initexpression
   * @until #//initexpression
   * @skipline #//setConstructedType
   * @until #//setConstructedType
   *
   * @param     newType         The tag of the type to be generated
   */
  void setConstructedType(std::string newType);

  XdmfArrayReference(XdmfArrayReference &);

protected:

  XdmfArrayReference();

  std::string mConstructedType;
  std::map<std::string, std::string> mConstructedProperties;

private:

  XdmfArrayReference(const XdmfArrayReference &);  // Not implemented.
  void operator=(const XdmfArrayReference &);  // Not implemented.
};

#endif

#ifdef __cplusplus
extern "C" {
#endif

// C wrappers go here

struct XDMFARRAYREFERENCE; // Simply as a typedef to ensure correct typing
typedef struct XDMFARRAYREFERENCE XDMFARRAYREFERENCE; 

XDMFCORE_EXPORT char * XdmfArrayReferenceGetConstructedType(XDMFARRAYREFERENCE * arrayReference);

XDMFCORE_EXPORT void * XdmfArrayReferenceRead(XDMFARRAYREFERENCE * arrayReference, int * status);

XDMFCORE_EXPORT void XdmfArrayReferenceSetConstructedProperties(XDMFARRAYREFERENCE * arrayReference, void * referenceobject);

XDMFCORE_EXPORT void XdmfArrayReferenceSetConstructedType(XDMFARRAYREFERENCE * arrayReference, char * newType);

// C Wrappers for parent classes are generated by macros

XDMF_ITEM_C_CHILD_DECLARE(XdmfArrayReference, XDMFARRAYREFERENCE, XDMFCORE)

#define XDMF_ARRAYREFERENCE_C_CHILD_DECLARE(ClassName, CClassName, Level)                                      \
                                                                                                               \
Level##_EXPORT char * ClassName##GetConstructedType( CClassName * arrayReference);                             \
Level##_EXPORT void * ClassName##Read( CClassName * arrayReference, int * status);                             \
Level##_EXPORT void ClassName##SetConstructedProperties( CClassName * arrayReference, void * referenceobject); \
Level##_EXPORT void ClassName##SetConstructedType( CClassName * arrayReference, char * newType);



#define XDMF_ARRAYREFERENCE_C_CHILD_WRAPPER(ClassName, CClassName)                                             \
                                                                                                               \
                                                                                                               \
char * ClassName##GetConstructedType(CClassName * arrayReference)                                              \
{                                                                                                              \
  return XdmfArrayReferenceGetConstructedType((XDMFARRAYREFERENCE *)((void *)arrayReference));                 \
}                                                                                                              \
                                                                                                               \
void * ClassName##Read(CClassName * arrayReference, int * status)                                              \
{                                                                                                              \
  return XdmfArrayReferenceRead((XDMFARRAYREFERENCE *)((void *)arrayReference), status);                       \
}                                                                                                              \
                                                                                                               \
void ClassName##SetConstructedProperties(CClassName * arrayReference, void * referenceobject)                  \
{                                                                                                              \
  XdmfArrayReferenceSetConstructedProperties((XDMFARRAYREFERENCE *)((void *)arrayReference), referenceobject); \
}                                                                                                              \
                                                                                                               \
void ClassName##SetConstructedType(CClassName * arrayReference, char * newType)                                \
{                                                                                                              \
  XdmfArrayReferenceSetConstructedType((XDMFARRAYREFERENCE *)((void *)arrayReference), newType);               \
}

#ifdef __cplusplus
}
#endif

#endif /* XDMFARRAYREFERENCE_HPP_ */
