/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#ifndef queryplan_TYPES_H
#define queryplan_TYPES_H

#include <Thrift.h>
#include <TApplicationException.h>
#include <protocol/TProtocol.h>
#include <transport/TTransport.h>



namespace Apache { namespace Hadoop { namespace Hive {

struct AdjacencyType {
  enum type {
    CONJUNCTIVE = 0,
    DISJUNCTIVE = 1
  };
};

struct NodeType {
  enum type {
    OPERATOR = 0,
    STAGE = 1
  };
};

struct OperatorType {
  enum type {
    JOIN = 0,
    MAPJOIN = 1,
    EXTRACT = 2,
    FILTER = 3,
    FORWARD = 4,
    GROUPBY = 5,
    LIMIT = 6,
    SCRIPT = 7,
    SELECT = 8,
    TABLESCAN = 9,
    FILESINK = 10,
    REDUCESINK = 11,
    UNION = 12,
    UDTF = 13,
    LATERALVIEWJOIN = 14,
    LATERALVIEWFORWARD = 15,
    HASHTABLESINK = 16,
    HASHTABLEDUMMY = 17
  };
};

struct TaskType {
  enum type {
    MAP = 0,
    REDUCE = 1,
    OTHER = 2
  };
};

struct StageType {
  enum type {
    CONDITIONAL = 0,
    COPY = 1,
    DDL = 2,
    MAPRED = 3,
    EXPLAIN = 4,
    FETCH = 5,
    FUNC = 6,
    MAPREDLOCAL = 7,
    MOVE = 8,
    STATS = 9
  };
};

typedef struct _Adjacency__isset {
  _Adjacency__isset() : node(false), children(false), adjacencyType(false) {}
  bool node;
  bool children;
  bool adjacencyType;
} _Adjacency__isset;

class Adjacency {
 public:

  static const char* ascii_fingerprint; // = "BC4F8C394677A1003AA9F56ED26D8204";
  static const uint8_t binary_fingerprint[16]; // = {0xBC,0x4F,0x8C,0x39,0x46,0x77,0xA1,0x00,0x3A,0xA9,0xF5,0x6E,0xD2,0x6D,0x82,0x04};

  Adjacency() : node("") {
  }

  virtual ~Adjacency() throw() {}

  std::string node;
  std::vector<std::string>  children;
  AdjacencyType::type adjacencyType;

  _Adjacency__isset __isset;

  bool operator == (const Adjacency & rhs) const
  {
    if (!(node == rhs.node))
      return false;
    if (!(children == rhs.children))
      return false;
    if (!(adjacencyType == rhs.adjacencyType))
      return false;
    return true;
  }
  bool operator != (const Adjacency &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Adjacency & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Graph__isset {
  _Graph__isset() : nodeType(false), roots(false), adjacencyList(false) {}
  bool nodeType;
  bool roots;
  bool adjacencyList;
} _Graph__isset;

class Graph {
 public:

  static const char* ascii_fingerprint; // = "1F7FB604B3EF8F7AFB5DEAD15F2FC0B5";
  static const uint8_t binary_fingerprint[16]; // = {0x1F,0x7F,0xB6,0x04,0xB3,0xEF,0x8F,0x7A,0xFB,0x5D,0xEA,0xD1,0x5F,0x2F,0xC0,0xB5};

  Graph() {
  }

  virtual ~Graph() throw() {}

  NodeType::type nodeType;
  std::vector<std::string>  roots;
  std::vector<Adjacency>  adjacencyList;

  _Graph__isset __isset;

  bool operator == (const Graph & rhs) const
  {
    if (!(nodeType == rhs.nodeType))
      return false;
    if (!(roots == rhs.roots))
      return false;
    if (!(adjacencyList == rhs.adjacencyList))
      return false;
    return true;
  }
  bool operator != (const Graph &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Graph & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Operator__isset {
  _Operator__isset() : operatorId(false), operatorType(false), operatorAttributes(false), operatorCounters(false), done(false), started(false) {}
  bool operatorId;
  bool operatorType;
  bool operatorAttributes;
  bool operatorCounters;
  bool done;
  bool started;
} _Operator__isset;

class Operator {
 public:

  static const char* ascii_fingerprint; // = "30917C758A752485AF223B697479DE6C";
  static const uint8_t binary_fingerprint[16]; // = {0x30,0x91,0x7C,0x75,0x8A,0x75,0x24,0x85,0xAF,0x22,0x3B,0x69,0x74,0x79,0xDE,0x6C};

  Operator() : operatorId(""), done(0), started(0) {
  }

  virtual ~Operator() throw() {}

  std::string operatorId;
  OperatorType::type operatorType;
  std::map<std::string, std::string>  operatorAttributes;
  std::map<std::string, int64_t>  operatorCounters;
  bool done;
  bool started;

  _Operator__isset __isset;

  bool operator == (const Operator & rhs) const
  {
    if (!(operatorId == rhs.operatorId))
      return false;
    if (!(operatorType == rhs.operatorType))
      return false;
    if (!(operatorAttributes == rhs.operatorAttributes))
      return false;
    if (!(operatorCounters == rhs.operatorCounters))
      return false;
    if (!(done == rhs.done))
      return false;
    if (!(started == rhs.started))
      return false;
    return true;
  }
  bool operator != (const Operator &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Operator & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Task__isset {
  _Task__isset() : taskId(false), taskType(false), taskAttributes(false), taskCounters(false), operatorGraph(false), operatorList(false), done(false), started(false) {}
  bool taskId;
  bool taskType;
  bool taskAttributes;
  bool taskCounters;
  bool operatorGraph;
  bool operatorList;
  bool done;
  bool started;
} _Task__isset;

class Task {
 public:

  static const char* ascii_fingerprint; // = "AC741A136EFA51843AFC3A12F6A793D1";
  static const uint8_t binary_fingerprint[16]; // = {0xAC,0x74,0x1A,0x13,0x6E,0xFA,0x51,0x84,0x3A,0xFC,0x3A,0x12,0xF6,0xA7,0x93,0xD1};

  Task() : taskId(""), done(0), started(0) {
  }

  virtual ~Task() throw() {}

  std::string taskId;
  TaskType::type taskType;
  std::map<std::string, std::string>  taskAttributes;
  std::map<std::string, int64_t>  taskCounters;
  Graph operatorGraph;
  std::vector<Operator>  operatorList;
  bool done;
  bool started;

  _Task__isset __isset;

  bool operator == (const Task & rhs) const
  {
    if (!(taskId == rhs.taskId))
      return false;
    if (!(taskType == rhs.taskType))
      return false;
    if (!(taskAttributes == rhs.taskAttributes))
      return false;
    if (!(taskCounters == rhs.taskCounters))
      return false;
    if (__isset.operatorGraph != rhs.__isset.operatorGraph)
      return false;
    else if (__isset.operatorGraph && !(operatorGraph == rhs.operatorGraph))
      return false;
    if (__isset.operatorList != rhs.__isset.operatorList)
      return false;
    else if (__isset.operatorList && !(operatorList == rhs.operatorList))
      return false;
    if (!(done == rhs.done))
      return false;
    if (!(started == rhs.started))
      return false;
    return true;
  }
  bool operator != (const Task &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Task & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Stage__isset {
  _Stage__isset() : stageId(false), stageType(false), stageAttributes(false), stageCounters(false), taskList(false), done(false), started(false) {}
  bool stageId;
  bool stageType;
  bool stageAttributes;
  bool stageCounters;
  bool taskList;
  bool done;
  bool started;
} _Stage__isset;

class Stage {
 public:

  static const char* ascii_fingerprint; // = "86EA3C7B0690AFED21A3D479E2B32378";
  static const uint8_t binary_fingerprint[16]; // = {0x86,0xEA,0x3C,0x7B,0x06,0x90,0xAF,0xED,0x21,0xA3,0xD4,0x79,0xE2,0xB3,0x23,0x78};

  Stage() : stageId(""), done(0), started(0) {
  }

  virtual ~Stage() throw() {}

  std::string stageId;
  StageType::type stageType;
  std::map<std::string, std::string>  stageAttributes;
  std::map<std::string, int64_t>  stageCounters;
  std::vector<Task>  taskList;
  bool done;
  bool started;

  _Stage__isset __isset;

  bool operator == (const Stage & rhs) const
  {
    if (!(stageId == rhs.stageId))
      return false;
    if (!(stageType == rhs.stageType))
      return false;
    if (!(stageAttributes == rhs.stageAttributes))
      return false;
    if (!(stageCounters == rhs.stageCounters))
      return false;
    if (!(taskList == rhs.taskList))
      return false;
    if (!(done == rhs.done))
      return false;
    if (!(started == rhs.started))
      return false;
    return true;
  }
  bool operator != (const Stage &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Stage & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Query__isset {
  _Query__isset() : queryId(false), queryType(false), queryAttributes(false), queryCounters(false), stageGraph(false), stageList(false), done(false), started(false) {}
  bool queryId;
  bool queryType;
  bool queryAttributes;
  bool queryCounters;
  bool stageGraph;
  bool stageList;
  bool done;
  bool started;
} _Query__isset;

class Query {
 public:

  static const char* ascii_fingerprint; // = "68300D63A5D40F2D17B9A9440FF626C1";
  static const uint8_t binary_fingerprint[16]; // = {0x68,0x30,0x0D,0x63,0xA5,0xD4,0x0F,0x2D,0x17,0xB9,0xA9,0x44,0x0F,0xF6,0x26,0xC1};

  Query() : queryId(""), queryType(""), done(0), started(0) {
  }

  virtual ~Query() throw() {}

  std::string queryId;
  std::string queryType;
  std::map<std::string, std::string>  queryAttributes;
  std::map<std::string, int64_t>  queryCounters;
  Graph stageGraph;
  std::vector<Stage>  stageList;
  bool done;
  bool started;

  _Query__isset __isset;

  bool operator == (const Query & rhs) const
  {
    if (!(queryId == rhs.queryId))
      return false;
    if (!(queryType == rhs.queryType))
      return false;
    if (!(queryAttributes == rhs.queryAttributes))
      return false;
    if (!(queryCounters == rhs.queryCounters))
      return false;
    if (!(stageGraph == rhs.stageGraph))
      return false;
    if (!(stageList == rhs.stageList))
      return false;
    if (!(done == rhs.done))
      return false;
    if (!(started == rhs.started))
      return false;
    return true;
  }
  bool operator != (const Query &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Query & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryPlan__isset {
  _QueryPlan__isset() : queries(false), done(false), started(false) {}
  bool queries;
  bool done;
  bool started;
} _QueryPlan__isset;

class QueryPlan {
 public:

  static const char* ascii_fingerprint; // = "3418D1B0C20C288C8406186700B772E3";
  static const uint8_t binary_fingerprint[16]; // = {0x34,0x18,0xD1,0xB0,0xC2,0x0C,0x28,0x8C,0x84,0x06,0x18,0x67,0x00,0xB7,0x72,0xE3};

  QueryPlan() : done(0), started(0) {
  }

  virtual ~QueryPlan() throw() {}

  std::vector<Query>  queries;
  bool done;
  bool started;

  _QueryPlan__isset __isset;

  bool operator == (const QueryPlan & rhs) const
  {
    if (!(queries == rhs.queries))
      return false;
    if (!(done == rhs.done))
      return false;
    if (!(started == rhs.started))
      return false;
    return true;
  }
  bool operator != (const QueryPlan &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryPlan & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

}}} // namespace

#endif
