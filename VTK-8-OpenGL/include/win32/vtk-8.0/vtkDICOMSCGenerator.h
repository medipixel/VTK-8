/*=========================================================================

  Program: DICOM for VTK

  Copyright (c) 2012-2017 David Gobbi
  All rights reserved.
  See Copyright.txt or http://dgobbi.github.io/bsd3.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtkDICOMSCGenerator_h
#define vtkDICOMSCGenerator_h

#include "vtkDICOMModule.h" // For export macro
#include "vtkDICOMGenerator.h"

//! Generate DICOM data objects for Secondary Capture images.
/*!
 *  Generate a DICOM data set belonging to one of the Secondary Capture
 *  classes.  This is for images that were not directly captured by
 *  medical imaging equipment.  For example, a screen capture or a
 *  digital film scan should be considered to be a secondary capture.
 *  The specific IOD classes supported are as follows:
 *  - Secondary Capture, 1.2.840.10008.5.1.4.1.1.7
 *  - Multi-frame Grayscale Byte SC, 1.2.840.10008.5.1.4.1.1.7.2
 *  - Multi-frame Grayscale Word SC, 1.2.840.10008.5.1.4.1.1.7.3
 *  - Multi-frame True Color SC, 1.2.840.10008.5.1.4.1.1.7.4
 */
class VTKDICOM_EXPORT vtkDICOMSCGenerator : public vtkDICOMGenerator
{
public:
  //! Static method for construction.
  static vtkDICOMSCGenerator *New();
  vtkTypeMacro(vtkDICOMSCGenerator, vtkDICOMGenerator);

  //! Print information about this object.
#ifdef VTK_OVERRIDE
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;
#else
  void PrintSelf(ostream& os, vtkIndent indent);
#endif

  //! Generate an instance of one of the supported classes.
  /*!
   *  This is the primary interface method of this class.  Given the
   *  information for a vtkImageData object, it will populate the
   *  attributes of the supplied vtkDICOMMetaData object.
   */
#ifdef VTK_OVERRIDE
  bool GenerateInstance(vtkInformation *info) VTK_OVERRIDE;
#else
  bool GenerateInstance(vtkInformation *info);
#endif

protected:
  vtkDICOMSCGenerator();
  ~vtkDICOMSCGenerator();

  //! Generate the SC Equipment Module.
  virtual bool GenerateSCEquipmentModule(vtkDICOMMetaData *source);

  //! Generate the SC Image Module.
  virtual bool GenerateSCImageModule(vtkDICOMMetaData *source);

  //! Generate the SC Multi-Frame Image Module.
  virtual bool GenerateSCMultiFrameImageModule(vtkDICOMMetaData *source);

  //! Instantiate a DICOM Secondary Capture Image object.
  virtual bool GenerateSCInstance(vtkInformation *info);

  //! Instantiate a DICOM Secondary Capture Image object.
  virtual bool GenerateSCMultiFrameInstance(vtkInformation *info);

private:
#ifdef VTK_DELETE_FUNCTION
  vtkDICOMSCGenerator(const vtkDICOMSCGenerator&) VTK_DELETE_FUNCTION;
  void operator=(const vtkDICOMSCGenerator&) VTK_DELETE_FUNCTION;
#elif __cplusplus >= 201103L
  vtkDICOMSCGenerator(const vtkDICOMSCGenerator&) = delete;
  void operator=(const vtkDICOMSCGenerator&) = delete;
#else
  vtkDICOMSCGenerator(const vtkDICOMSCGenerator&);
  void operator=(const vtkDICOMSCGenerator&);
#endif
};

#endif // vtkDICOMSCGenerator_h
