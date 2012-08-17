/*
 * FilteringPositionExtractor.h
 *
 *  Created on: 27.07.2012
 *      Author: poschmann
 */

#ifndef FILTERINGPOSITIONEXTRACTOR_H_
#define FILTERINGPOSITIONEXTRACTOR_H_

#include "tracking/PositionExtractor.h"
#include "boost/shared_ptr.hpp"

using boost::shared_ptr;

namespace tracking {

/**
 * Position extractor that filters the samples leaving only those that represent the searched object
 * and delegates to another extractor.
 */
class FilteringPositionExtractor : public PositionExtractor {
public:

	/**
	 * Constructs a new filtering position extractor.
	 *
	 * @param[in] extractor The wrapped position extractor.
	 */
	explicit FilteringPositionExtractor(shared_ptr<PositionExtractor> extractor);

	~FilteringPositionExtractor();

	boost::optional<Sample> extract(const std::vector<Sample>& samples);

private:
	shared_ptr<PositionExtractor> extractor; ///< The wrapped position extractor.
};

} /* namespace tracking */
#endif /* FILTERINGPOSITIONEXTRACTOR_H_ */
