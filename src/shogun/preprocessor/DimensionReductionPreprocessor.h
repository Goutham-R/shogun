/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2011 Sergey Lisitsyn
 * Copyright (C) 2011 Berlin Institute of Technology and Max-Planck-Society
 */

#ifndef DIMENSIONREDUCTIONPREPROCESSOR_H_
#define DIMENSIONREDUCTIONPREPROCESSOR_H_

#include <shogun/preprocessor/SimplePreprocessor.h>
#include <shogun/features/Features.h>
#include <shogun/distance/Distance.h>

namespace shogun
{

class CFeatures;
class CDistance;
class CKernel;

/** @brief the class DimensionReductionPreprocessor, a base
 * class for preprocessors used to lower the dimensionality of given 
 * simple features (dense matrices). 
 */
class CDimensionReductionPreprocessor: public CSimplePreprocessor<float64_t>
{
public:

	/* constructor */
	CDimensionReductionPreprocessor();

	/* destructor */
	virtual ~CDimensionReductionPreprocessor();

	/** init
	 * set true by default, should be defined if dimension reduction
	 * preprocessor is using some initialization
	 */
	virtual bool init(CFeatures* data);

	/** cleanup
	 * set empty by default, should be defined if dimension reduction
	 * preprocessor should free some resources
	 */
	virtual void cleanup();

	/** apply preproc to feature matrix
	 * by default does nothing, returns given features' matrix
	 */
	virtual SGMatrix<float64_t> apply_to_feature_matrix(CFeatures* features);

	/** apply preproc to feature vector
	 * by default does nothing, returns given feature vector
	 */
	virtual SGVector<float64_t> apply_to_feature_vector(SGVector<float64_t> vector);

	/** get name */
	virtual const char* get_name() const { return "DimensionReductionPreprocessor"; };

	/** get type */
	virtual EPreprocessorType get_type() const;

	/** setter for target dimension
	 * @param dim target dimension
	 */
	void set_target_dim(int32_t dim);

	/** getter for target dimension
	 * @return target dimension
	 */
	int32_t get_target_dim() const;

	/** setter for distance
	 * @param distance distance to set
	 */
	void set_distance(CDistance* distance);

	/** setter for kernel
	 * @param kernel kernel to set
	 */
	void set_kernel(CKernel* kernel);

public:

	/** const indicating target dimensionality should be determined automagically */
	static const int32_t AUTO_TARGET_DIM = -1;

protected:

	/** detect dimensionality from distance matrix 
	 * @param distance_matrix distance matrix to be used 
	 * @return detected dimensionality 
	 */
	virtual int32_t detect_dim(SGMatrix<float64_t> distance_matrix);

	/** default init */
	void init();

protected:

	/** target dim of dimensionality reduction preprocessor */
	int32_t m_target_dim;

	/** distance to be used */
	CDistance* m_distance;

	/** kernel to be used */
	CKernel* m_kernel;
};
}

#endif /* DIMENSIONREDUCTIONPREPROCESSOR_H_ */
