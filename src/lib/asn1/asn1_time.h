/*
* ASN.1 Time Representation
* (C) 1999-2007,2012 Jack Lloyd
*
* Botan is released under the Simplified BSD License (see license.txt)
*/

#ifndef BOTAN_ASN1_TIME_H__
#define BOTAN_ASN1_TIME_H__

#include <botan/asn1_obj.h>
#include <chrono>

namespace Botan {

/**
* X.509 Time
*/
class BOTAN_DLL X509_Time : public ASN1_Object
   {
   public:
      void encode_into(class DER_Encoder&) const override;
      void decode_from(class BER_Decoder&) override;

      std::string as_string() const;
      std::string readable_string() const;
      bool time_is_set() const;

      std::string to_string() const { return readable_string(); }

      s32bit cmp(const X509_Time&) const;

      void set_to(const std::string&);
      void set_to(const std::string&, ASN1_Tag);

      X509_Time(const std::chrono::system_clock::time_point& time);
      X509_Time(const std::string& = "");
      X509_Time(const std::string&, ASN1_Tag);
   private:
      bool passes_sanity_check() const;
      u32bit year, month, day, hour, minute, second;
      ASN1_Tag tag;
   };

/*
* Comparison Operations
*/
bool BOTAN_DLL operator==(const X509_Time&, const X509_Time&);
bool BOTAN_DLL operator!=(const X509_Time&, const X509_Time&);
bool BOTAN_DLL operator<=(const X509_Time&, const X509_Time&);
bool BOTAN_DLL operator>=(const X509_Time&, const X509_Time&);
bool BOTAN_DLL operator<(const X509_Time&, const X509_Time&);
bool BOTAN_DLL operator>(const X509_Time&, const X509_Time&);

}

#endif
