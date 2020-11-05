/**
 * Autogenerated by Thrift Compiler (0.12.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef MovieReviewService_H
#define MovieReviewService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "media_service_types.h"

namespace media_service {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class MovieReviewServiceIf {
 public:
  virtual ~MovieReviewServiceIf() {}
  virtual void UploadMovieReview(const int64_t req_id, const std::string& movie_id, const int64_t review_id, const int64_t timestamp, const std::map<std::string, std::string> & carrier) = 0;
  virtual void ReadMovieReviews(std::vector<Review> & _return, const int64_t req_id, const std::string& movie_id, const int32_t start, const int32_t stop, const std::map<std::string, std::string> & carrier) = 0;
};

class MovieReviewServiceIfFactory {
 public:
  typedef MovieReviewServiceIf Handler;

  virtual ~MovieReviewServiceIfFactory() {}

  virtual MovieReviewServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(MovieReviewServiceIf* /* handler */) = 0;
};

class MovieReviewServiceIfSingletonFactory : virtual public MovieReviewServiceIfFactory {
 public:
  MovieReviewServiceIfSingletonFactory(const ::apache::thrift::stdcxx::shared_ptr<MovieReviewServiceIf>& iface) : iface_(iface) {}
  virtual ~MovieReviewServiceIfSingletonFactory() {}

  virtual MovieReviewServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(MovieReviewServiceIf* /* handler */) {}

 protected:
  ::apache::thrift::stdcxx::shared_ptr<MovieReviewServiceIf> iface_;
};

class MovieReviewServiceNull : virtual public MovieReviewServiceIf {
 public:
  virtual ~MovieReviewServiceNull() {}
  void UploadMovieReview(const int64_t /* req_id */, const std::string& /* movie_id */, const int64_t /* review_id */, const int64_t /* timestamp */, const std::map<std::string, std::string> & /* carrier */) {
    return;
  }
  void ReadMovieReviews(std::vector<Review> & /* _return */, const int64_t /* req_id */, const std::string& /* movie_id */, const int32_t /* start */, const int32_t /* stop */, const std::map<std::string, std::string> & /* carrier */) {
    return;
  }
};

typedef struct _MovieReviewService_UploadMovieReview_args__isset {
  _MovieReviewService_UploadMovieReview_args__isset() : req_id(false), movie_id(false), review_id(false), timestamp(false), carrier(false) {}
  bool req_id :1;
  bool movie_id :1;
  bool review_id :1;
  bool timestamp :1;
  bool carrier :1;
} _MovieReviewService_UploadMovieReview_args__isset;

class MovieReviewService_UploadMovieReview_args {
 public:

  MovieReviewService_UploadMovieReview_args(const MovieReviewService_UploadMovieReview_args&);
  MovieReviewService_UploadMovieReview_args& operator=(const MovieReviewService_UploadMovieReview_args&);
  MovieReviewService_UploadMovieReview_args() : req_id(0), movie_id(), review_id(0), timestamp(0) {
  }

  virtual ~MovieReviewService_UploadMovieReview_args() throw();
  int64_t req_id;
  std::string movie_id;
  int64_t review_id;
  int64_t timestamp;
  std::map<std::string, std::string>  carrier;

  _MovieReviewService_UploadMovieReview_args__isset __isset;

  void __set_req_id(const int64_t val);

  void __set_movie_id(const std::string& val);

  void __set_review_id(const int64_t val);

  void __set_timestamp(const int64_t val);

  void __set_carrier(const std::map<std::string, std::string> & val);

  bool operator == (const MovieReviewService_UploadMovieReview_args & rhs) const
  {
    if (!(req_id == rhs.req_id))
      return false;
    if (!(movie_id == rhs.movie_id))
      return false;
    if (!(review_id == rhs.review_id))
      return false;
    if (!(timestamp == rhs.timestamp))
      return false;
    if (!(carrier == rhs.carrier))
      return false;
    return true;
  }
  bool operator != (const MovieReviewService_UploadMovieReview_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MovieReviewService_UploadMovieReview_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class MovieReviewService_UploadMovieReview_pargs {
 public:


  virtual ~MovieReviewService_UploadMovieReview_pargs() throw();
  const int64_t* req_id;
  const std::string* movie_id;
  const int64_t* review_id;
  const int64_t* timestamp;
  const std::map<std::string, std::string> * carrier;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MovieReviewService_UploadMovieReview_result__isset {
  _MovieReviewService_UploadMovieReview_result__isset() : se(false) {}
  bool se :1;
} _MovieReviewService_UploadMovieReview_result__isset;

class MovieReviewService_UploadMovieReview_result {
 public:

  MovieReviewService_UploadMovieReview_result(const MovieReviewService_UploadMovieReview_result&);
  MovieReviewService_UploadMovieReview_result& operator=(const MovieReviewService_UploadMovieReview_result&);
  MovieReviewService_UploadMovieReview_result() {
  }

  virtual ~MovieReviewService_UploadMovieReview_result() throw();
  ServiceException se;

  _MovieReviewService_UploadMovieReview_result__isset __isset;

  void __set_se(const ServiceException& val);

  bool operator == (const MovieReviewService_UploadMovieReview_result & rhs) const
  {
    if (!(se == rhs.se))
      return false;
    return true;
  }
  bool operator != (const MovieReviewService_UploadMovieReview_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MovieReviewService_UploadMovieReview_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MovieReviewService_UploadMovieReview_presult__isset {
  _MovieReviewService_UploadMovieReview_presult__isset() : se(false) {}
  bool se :1;
} _MovieReviewService_UploadMovieReview_presult__isset;

class MovieReviewService_UploadMovieReview_presult {
 public:


  virtual ~MovieReviewService_UploadMovieReview_presult() throw();
  ServiceException se;

  _MovieReviewService_UploadMovieReview_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _MovieReviewService_ReadMovieReviews_args__isset {
  _MovieReviewService_ReadMovieReviews_args__isset() : req_id(false), movie_id(false), start(false), stop(false), carrier(false) {}
  bool req_id :1;
  bool movie_id :1;
  bool start :1;
  bool stop :1;
  bool carrier :1;
} _MovieReviewService_ReadMovieReviews_args__isset;

class MovieReviewService_ReadMovieReviews_args {
 public:

  MovieReviewService_ReadMovieReviews_args(const MovieReviewService_ReadMovieReviews_args&);
  MovieReviewService_ReadMovieReviews_args& operator=(const MovieReviewService_ReadMovieReviews_args&);
  MovieReviewService_ReadMovieReviews_args() : req_id(0), movie_id(), start(0), stop(0) {
  }

  virtual ~MovieReviewService_ReadMovieReviews_args() throw();
  int64_t req_id;
  std::string movie_id;
  int32_t start;
  int32_t stop;
  std::map<std::string, std::string>  carrier;

  _MovieReviewService_ReadMovieReviews_args__isset __isset;

  void __set_req_id(const int64_t val);

  void __set_movie_id(const std::string& val);

  void __set_start(const int32_t val);

  void __set_stop(const int32_t val);

  void __set_carrier(const std::map<std::string, std::string> & val);

  bool operator == (const MovieReviewService_ReadMovieReviews_args & rhs) const
  {
    if (!(req_id == rhs.req_id))
      return false;
    if (!(movie_id == rhs.movie_id))
      return false;
    if (!(start == rhs.start))
      return false;
    if (!(stop == rhs.stop))
      return false;
    if (!(carrier == rhs.carrier))
      return false;
    return true;
  }
  bool operator != (const MovieReviewService_ReadMovieReviews_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MovieReviewService_ReadMovieReviews_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class MovieReviewService_ReadMovieReviews_pargs {
 public:


  virtual ~MovieReviewService_ReadMovieReviews_pargs() throw();
  const int64_t* req_id;
  const std::string* movie_id;
  const int32_t* start;
  const int32_t* stop;
  const std::map<std::string, std::string> * carrier;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MovieReviewService_ReadMovieReviews_result__isset {
  _MovieReviewService_ReadMovieReviews_result__isset() : success(false), se(false) {}
  bool success :1;
  bool se :1;
} _MovieReviewService_ReadMovieReviews_result__isset;

class MovieReviewService_ReadMovieReviews_result {
 public:

  MovieReviewService_ReadMovieReviews_result(const MovieReviewService_ReadMovieReviews_result&);
  MovieReviewService_ReadMovieReviews_result& operator=(const MovieReviewService_ReadMovieReviews_result&);
  MovieReviewService_ReadMovieReviews_result() {
  }

  virtual ~MovieReviewService_ReadMovieReviews_result() throw();
  std::vector<Review>  success;
  ServiceException se;

  _MovieReviewService_ReadMovieReviews_result__isset __isset;

  void __set_success(const std::vector<Review> & val);

  void __set_se(const ServiceException& val);

  bool operator == (const MovieReviewService_ReadMovieReviews_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(se == rhs.se))
      return false;
    return true;
  }
  bool operator != (const MovieReviewService_ReadMovieReviews_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MovieReviewService_ReadMovieReviews_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MovieReviewService_ReadMovieReviews_presult__isset {
  _MovieReviewService_ReadMovieReviews_presult__isset() : success(false), se(false) {}
  bool success :1;
  bool se :1;
} _MovieReviewService_ReadMovieReviews_presult__isset;

class MovieReviewService_ReadMovieReviews_presult {
 public:


  virtual ~MovieReviewService_ReadMovieReviews_presult() throw();
  std::vector<Review> * success;
  ServiceException se;

  _MovieReviewService_ReadMovieReviews_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class MovieReviewServiceClient : virtual public MovieReviewServiceIf {
 public:
  MovieReviewServiceClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  MovieReviewServiceClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void UploadMovieReview(const int64_t req_id, const std::string& movie_id, const int64_t review_id, const int64_t timestamp, const std::map<std::string, std::string> & carrier);
  void send_UploadMovieReview(const int64_t req_id, const std::string& movie_id, const int64_t review_id, const int64_t timestamp, const std::map<std::string, std::string> & carrier);
  void recv_UploadMovieReview();
  void ReadMovieReviews(std::vector<Review> & _return, const int64_t req_id, const std::string& movie_id, const int32_t start, const int32_t stop, const std::map<std::string, std::string> & carrier);
  void send_ReadMovieReviews(const int64_t req_id, const std::string& movie_id, const int32_t start, const int32_t stop, const std::map<std::string, std::string> & carrier);
  void recv_ReadMovieReviews(std::vector<Review> & _return);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class MovieReviewServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::apache::thrift::stdcxx::shared_ptr<MovieReviewServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (MovieReviewServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_UploadMovieReview(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_ReadMovieReviews(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  MovieReviewServiceProcessor(::apache::thrift::stdcxx::shared_ptr<MovieReviewServiceIf> iface) :
    iface_(iface) {
    processMap_["UploadMovieReview"] = &MovieReviewServiceProcessor::process_UploadMovieReview;
    processMap_["ReadMovieReviews"] = &MovieReviewServiceProcessor::process_ReadMovieReviews;
  }

  virtual ~MovieReviewServiceProcessor() {}
};

class MovieReviewServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  MovieReviewServiceProcessorFactory(const ::apache::thrift::stdcxx::shared_ptr< MovieReviewServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::apache::thrift::stdcxx::shared_ptr< MovieReviewServiceIfFactory > handlerFactory_;
};

class MovieReviewServiceMultiface : virtual public MovieReviewServiceIf {
 public:
  MovieReviewServiceMultiface(std::vector<apache::thrift::stdcxx::shared_ptr<MovieReviewServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~MovieReviewServiceMultiface() {}
 protected:
  std::vector<apache::thrift::stdcxx::shared_ptr<MovieReviewServiceIf> > ifaces_;
  MovieReviewServiceMultiface() {}
  void add(::apache::thrift::stdcxx::shared_ptr<MovieReviewServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void UploadMovieReview(const int64_t req_id, const std::string& movie_id, const int64_t review_id, const int64_t timestamp, const std::map<std::string, std::string> & carrier) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->UploadMovieReview(req_id, movie_id, review_id, timestamp, carrier);
    }
    ifaces_[i]->UploadMovieReview(req_id, movie_id, review_id, timestamp, carrier);
  }

  void ReadMovieReviews(std::vector<Review> & _return, const int64_t req_id, const std::string& movie_id, const int32_t start, const int32_t stop, const std::map<std::string, std::string> & carrier) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->ReadMovieReviews(_return, req_id, movie_id, start, stop, carrier);
    }
    ifaces_[i]->ReadMovieReviews(_return, req_id, movie_id, start, stop, carrier);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class MovieReviewServiceConcurrentClient : virtual public MovieReviewServiceIf {
 public:
  MovieReviewServiceConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  MovieReviewServiceConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void UploadMovieReview(const int64_t req_id, const std::string& movie_id, const int64_t review_id, const int64_t timestamp, const std::map<std::string, std::string> & carrier);
  int32_t send_UploadMovieReview(const int64_t req_id, const std::string& movie_id, const int64_t review_id, const int64_t timestamp, const std::map<std::string, std::string> & carrier);
  void recv_UploadMovieReview(const int32_t seqid);
  void ReadMovieReviews(std::vector<Review> & _return, const int64_t req_id, const std::string& movie_id, const int32_t start, const int32_t stop, const std::map<std::string, std::string> & carrier);
  int32_t send_ReadMovieReviews(const int64_t req_id, const std::string& movie_id, const int32_t start, const int32_t stop, const std::map<std::string, std::string> & carrier);
  void recv_ReadMovieReviews(std::vector<Review> & _return, const int32_t seqid);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

} // namespace

#endif