// ArduinoJson - https://arduinojson.org
// Copyright © 2014-2023, Benoit BLANCHON
// MIT License

#pragma once

#include <ArduinoJson/Array/ArrayData.hpp>
#include <ArduinoJson/Numbers/JsonFloat.hpp>
#include <ArduinoJson/Numbers/JsonInteger.hpp>
#include <ArduinoJson/Object/ObjectData.hpp>

ARDUINOJSON_BEGIN_PRIVATE_NAMESPACE

template <typename TResult>
struct VariantDataVisitor {
  typedef TResult result_type;

  TResult visitArray(const ArrayData&) {
    return TResult();
  }

  TResult visitBoolean(bool) {
    return TResult();
  }

  TResult visitFloat(JsonFloat) {
    return TResult();
  }

  TResult visitSignedInteger(JsonInteger) {
    return TResult();
  }

  TResult visitNull(nullptr_t) {
    return TResult();
  }

  TResult visitObject(const ObjectData&) {
    return TResult();
  }

  TResult visitUnsignedInteger(JsonUInt) {
    return TResult();
  }

  TResult visitRawString(RawString) {
    return TResult();
  }

  TResult visitString(JsonString) {
    return TResult();
  }
};

ARDUINOJSON_END_PRIVATE_NAMESPACE