// ====================================================================== 
// \title  MathReceiver.hpp
// \author anniesmith
// \brief  cpp file for MathReceiver test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include "Tester.hpp"

#define INSTANCE 0
#define MAX_HISTORY_SIZE 10
#define QUEUE_DEPTH 10

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction and destruction
  // ----------------------------------------------------------------------

  Tester ::
    Tester(void) :
#if FW_OBJECT_NAMES == 1
      MathReceiverGTestBase("Tester", MAX_HISTORY_SIZE),
      component("MathReceiver")
#else
      MathReceiverGTestBase(MAX_HISTORY_SIZE),
      component()
#endif
  {
    this->initComponents();
    this->connectPorts();
  }

  Tester ::
    ~Tester(void)
  {

  }

  // ----------------------------------------------------------------------
  // Tests
  // ----------------------------------------------------------------------

  void Tester ::
    testAddCommand(void)
  {
    // load parameters
    this->component.loadParameters();

    //invoke operation port with add operation
    this->invoke_to_mathIn(0,2.0,3.0,Ref::MATH_ADD);
    //invoke scheduler port to dispatch massage
    this->invoke_to_SchedIn(0,0);

    //verify the operation port was called as expected
    ASSERT_FROM_PORT_HISTORY_SIZE(1);
    ASSERT_from_mathOut_SIZE(1);
    //because factor1 is the default (0), the result will be zero
    ASSERT_from_mathOut(0,0.0);

    //verify telemetry and events

    //the event and telemetry channel use the Ref::MathOp type for values
    Ref::MathOp checkOp(2.0, 3.0, Ref::ADD, 0.0);

    //check there was only one event
    ASSERT_EVENTS_SIZE(1);
    //check it was the op event
    ASSERT_EVENTS_MR_OPERATION_PERFORMED_SIZE(1);
    //check that the event has the correct argument
    ASSERT_EVENTS_MR_OPERATION_PERFORMED(0, checkOp);

    //check there was only one channel written
    ASSERT_TLM_SIZE(1);
    //check that is was the op channel
    ASSERT_TLM_MR_OPERATION_SIZE(1);
    //check for the correct value of the channel
    ASSERT_TLM_MR_OPERATION(0, checkOp);

    //clear the history before sending the command
    this->clearHistory();
    //send the command to set factor1 to 2.0
    this->sendCmd_MR_SET_FACTOR1(0, 10, 2.0);
    //invoke scheduler port to dispatch message
    this->invoke_to_SchedIn(0,0);
    //verify the changed value events
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MR_SET_FACTOR1_SIZE(1);
    ASSERT_EVENTS_MR_SET_FACTOR1(0,2.0);
    //verify the changed value channel
    ASSERT_TLM_SIZE(2);
    ASSERT_TLM_MR_FACTOR1_SIZE(1);
    ASSERT_TLM_MR_FACTOR1(0,2.0);
    ASSERT_TLM_MR_FACTOR1S_SIZE(1);
    ASSERT_TLM_MR_FACTOR1S(0,1);
    //verify the command response was sent
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0, MathReceiverComponentBase::OPCODE_MR_SET_FACTOR1, 10, Fw::COMMAND_OK);
    //could now repeat the add command with the new factor
  }

  // ----------------------------------------------------------------------
  // Handlers for typed from ports
  // ----------------------------------------------------------------------

  void Tester ::
    from_mathOut_handler(
        const NATIVE_INT_TYPE portNum,
        F32 result
    )
  {
    this->pushFromPortEntry_mathOut(result);
  }

  // ----------------------------------------------------------------------
  // Helper methods 
  // ----------------------------------------------------------------------

  void Tester ::
    connectPorts(void) 
  {

    // mathIn
    this->connect_to_mathIn(
        0,
        this->component.get_mathIn_InputPort(0)
    );

    // SchedIn
    this->connect_to_SchedIn(
        0,
        this->component.get_SchedIn_InputPort(0)
    );

    // CmdDisp
    this->connect_to_CmdDisp(
        0,
        this->component.get_CmdDisp_InputPort(0)
    );

    // mathOut
    this->component.set_mathOut_OutputPort(
        0, 
        this->get_from_mathOut(0)
    );

    // CmdStatus
    this->component.set_CmdStatus_OutputPort(
        0, 
        this->get_from_CmdStatus(0)
    );

    // CmdReg
    this->component.set_CmdReg_OutputPort(
        0, 
        this->get_from_CmdReg(0)
    );

    // ParamGet
    this->component.set_ParamGet_OutputPort(
        0, 
        this->get_from_ParamGet(0)
    );

    // ParamSet
    this->component.set_ParamSet_OutputPort(
        0, 
        this->get_from_ParamSet(0)
    );

    // Tlm
    this->component.set_Tlm_OutputPort(
        0, 
        this->get_from_Tlm(0)
    );

    // Time
    this->component.set_Time_OutputPort(
        0, 
        this->get_from_Time(0)
    );

    // Log
    this->component.set_Log_OutputPort(
        0, 
        this->get_from_Log(0)
    );

    // LogText
    this->component.set_LogText_OutputPort(
        0, 
        this->get_from_LogText(0)
    );




  }

  void Tester ::
    initComponents(void) 
  {
    this->init();
    this->component.init(
        QUEUE_DEPTH, INSTANCE
    );
  }

} // end namespace Ref
