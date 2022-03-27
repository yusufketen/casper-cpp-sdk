#pragma once

#include "Definitions.h"
#include "Types/PublicKey.h"
#include "nlohmann/json.hpp"

namespace Casper {
/// <summary>
/// A validator's weight.
/// </summary>
struct ValidatorWeight {
  /// <summary>
  /// Validator's Public Key.
  /// </summary>
  PublicKey public_key;

  /// <summary>
  /// Validator's weight.
  /// </summary>
  big_int weight;

  ValidatorWeight() {}
};

/**
 * @brief Construct a JSON object from a ValidatorWeight object.
 *
 * @param j JSON object to construct.
 * @param p ValidatorWeight object to construct from.
 */
inline void to_json(nlohmann::json& j, const ValidatorWeight& p) {
  j = nlohmann::json{{"public_key", p.public_key},
                     {"weight", p.weight.toString()}};
}

/**
 * @brief Construct a ValidatorWeight object from a JSON object.
 *
 * @param j JSON object to construct the object from.
 * @param p ValidatorWeight object to construct.
 */
inline void from_json(const nlohmann::json& j, ValidatorWeight& p) {
  // TODO: PublicKey = PublicKey.FromHexString(publicKey),
  std::string weightString = j.at("weight").get<std::string>();
  if (weightString.size() > 0) {
    p.weight = weightString;
  } else {
    p.weight = 0;
  }

  j.at("public_key").get_to(p.public_key);
}
}  // namespace Casper