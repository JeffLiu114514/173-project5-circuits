
#include <stdio.h>
#include <stdlib.h>
#include "Circuit.h"

//static Circuit* and3_Circuit() {
//
//	char *title = "Two AND gates connected to make a 3-input AND circuit";
//
//	// Create the inputs
//	int NINPUTS = 3;
//	Boolean* x = new_Boolean(false);
//	Boolean* y = new_Boolean(false);
//	Boolean* z = new_Boolean(false);
//	Boolean** inputs = new_Boolean_array(NINPUTS);
//	inputs[0] = x;
//	inputs[1] = y;
//	inputs[2] = z;
//
//	// Create the outputs
//	int NOUTPUTS = 1;
//	Boolean* result = new_Boolean(false);
//	Boolean** outputs = new_Boolean_array(NOUTPUTS);
//	outputs[0] = result;
//
//	// Create the gates
//	int NGATES = 2;
//	Gate* A1 = new_AndGate();
//	Gate* A2 = new_AndGate();
//	Gate** gates = new_Gate_array(NGATES);
//	gates[0] = A1;
//	gates[1] = A2;
//
//	// Create the circuit
//	Circuit *circuit = new_Circuit(title,
//				       NINPUTS, inputs,
//				       NOUTPUTS, outputs,
//				       NGATES, gates);
//
//	// Connect the gates in the circuit
//	Circuit_connect(circuit, x, Gate_getInput(A1, 0));
//	Circuit_connect(circuit, y, Gate_getInput(A1, 1));
//	Boolean* x_and_y = Gate_getOutput(A1);
//
//	Circuit_connect(circuit, x_and_y, Gate_getInput(A2, 0));
//	Circuit_connect(circuit, z, Gate_getInput(A2, 1));
//	Boolean* x_and_y_and_z = Gate_getOutput(A2);
//
//	Circuit_connect(circuit, x_and_y_and_z, result);
//
//	// Done!
//	return circuit;
//}
//
//// You should not use this function in your project.
//// It is here to show you how to get and set values in a circuit using the API.
//// See the project description for what you are required to do.
//// Go to study session if you have questions about how to do it.
//static void test3In1Out(Circuit* circuit, bool in0, bool in1, bool in2) {
//    Circuit_setInput(circuit, 0, in0);
//    Circuit_setInput(circuit, 1, in1);
//    Circuit_setInput(circuit, 2, in2);
//    Circuit_update(circuit);
//    printf("%s %s %s -> %s\n",
//           Boolean_toString(Circuit_getInput(circuit, 0)),
//           Boolean_toString(Circuit_getInput(circuit, 1)),
//           Boolean_toString(Circuit_getInput(circuit, 2)),
//           Boolean_toString(Circuit_getOutput(circuit, 0)));
//}

//(x and y) or (not x)
static Circuit* circuitA() {
    char *title = "One AND gate between x and y and one NOT gate of x connected to a OR gate to "
                  "make a the circuit A";

    // Create the inputs
    int NINPUTS = 2;
    Boolean* x = new_Boolean(false);
    Boolean* y = new_Boolean(false);
    Boolean** inputs = new_Boolean_array(NINPUTS);
    inputs[0] = x;
    inputs[1] = y;

    // Create the outputs
    int NOUTPUTS = 1;
    Boolean* result = new_Boolean(false);
    Boolean** outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    // Create the gates
    int NGATES = 3;
    Gate* A1 = new_AndGate();
    Gate* A2 = new_Inverter();
    Gate* A3 = new_OrGate();
    Gate** gates = new_Gate_array(NGATES);
    gates[0] = A1;
    gates[1] = A2;
    gates[2] = A3;

    // Create the circuit
    Circuit *circuit = new_Circuit(title,
                                   NINPUTS, inputs,
                                   NOUTPUTS, outputs,
                                   NGATES, gates);

    // Connect the gates in the circuit
    Circuit_connect(circuit, x, Gate_getInput(A1, 0));
    Circuit_connect(circuit, y, Gate_getInput(A1, 1));
    Boolean* x_and_y = Gate_getOutput(A1);

    Circuit_connect(circuit, y, Gate_getInput(A2, 0));
    Boolean* not_y = Gate_getOutput(A2);

    Circuit_connect(circuit, x_and_y, Gate_getInput(A3, 0));
    Circuit_connect(circuit, not_y, Gate_getInput(A3, 1));
    Boolean* x_and_y_or_not_y = Gate_getOutput(A3);

    Circuit_connect(circuit, x_and_y_or_not_y, result);

    // Done!
    return circuit;
}

static void test2In1Out(Circuit* circuit, bool in0, bool in1) {
    Circuit_setInput(circuit, 0, in0);
    Circuit_setInput(circuit, 1, in1);
    Circuit_update(circuit);
    printf("%s %s -> %s\n",
           Boolean_toString(Circuit_getInput(circuit, 0)),
           Boolean_toString(Circuit_getInput(circuit, 1)),
           Boolean_toString(Circuit_getOutput(circuit, 0)));
}

static void test3In1Out(Circuit* circuit, bool in0, bool in1, bool in2) {
    Circuit_setInput(circuit, 0, in0);
    Circuit_setInput(circuit, 1, in1);
    Circuit_setInput(circuit, 2, in2);
    Circuit_update(circuit);
    printf("%s %s %s -> %s\n",
           Boolean_toString(Circuit_getInput(circuit, 0)),
           Boolean_toString(Circuit_getInput(circuit, 1)),
           Boolean_toString(Circuit_getInput(circuit, 2)),
           Boolean_toString(Circuit_getOutput(circuit, 0)));
}

//(x nor y) nor (x nor y)
static Circuit* circuitB() {
    char *title = "One NOR gate between x and y and one NOR gate between x and y connected to a NOR gate to "
                  "make a the circuit B";

    // Create the inputs
    int NINPUTS = 2;
    Boolean* x = new_Boolean(false);
    Boolean* y = new_Boolean(false);
    Boolean** inputs = new_Boolean_array(NINPUTS);
    inputs[0] = x;
    inputs[1] = y;

    // Create the outputs
    int NOUTPUTS = 1;
    Boolean* result = new_Boolean(false);
    Boolean** outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    // Create the gates
    int NGATES = 6;
    Gate* A1 = new_OrGate();
    Gate* A2 = new_Inverter();
    Gate* A3 = new_OrGate();
    Gate* A4 = new_Inverter();
    Gate* A5 = new_OrGate();
    Gate* A6 = new_Inverter();
    Gate** gates = new_Gate_array(NGATES);
    gates[0] = A1;
    gates[1] = A2;
    gates[2] = A3;
    gates[3] = A4;
    gates[4] = A5;
    gates[5] = A6;


    // Create the circuit
    Circuit *circuit = new_Circuit(title,
                                   NINPUTS, inputs,
                                   NOUTPUTS, outputs,
                                   NGATES, gates);

    // Connect the gates in the circuit
    Circuit_connect(circuit, x, Gate_getInput(A1, 0));
    Circuit_connect(circuit, y, Gate_getInput(A1, 1));
    Boolean* x_or_y = Gate_getOutput(A1);
    Circuit_connect(circuit, x_or_y, Gate_getInput(A2, 0));
    Boolean* x_nor_y = Gate_getOutput(A2);

    Circuit_connect(circuit, x, Gate_getInput(A3, 0));
    Circuit_connect(circuit, y, Gate_getInput(A3, 1));
    Boolean* x_or_y2 = Gate_getOutput(A3);
    Circuit_connect(circuit, x_or_y2, Gate_getInput(A4, 0));
    Boolean* x_nor_y2 = Gate_getOutput(A4);

    Circuit_connect(circuit, x_nor_y, Gate_getInput(A5, 0));
    Circuit_connect(circuit, x_nor_y2, Gate_getInput(A5, 1));
    Boolean* x_nor_y_or_x_nor_y = Gate_getOutput(A5);
    Circuit_connect(circuit, x_nor_y_or_x_nor_y, Gate_getInput(A6, 0));
    Boolean* x_nor_y_nor_x_nor_y = Gate_getOutput(A6);

    Circuit_connect(circuit, x_nor_y_nor_x_nor_y, result);

    // Done!
    return circuit;
}

//((x or not y) and (y or not z)) and (z or not x)
static Circuit* circuitC() {
    char *title = "((x or not y) and (y or not z)) and (z or not x) "
                  "make a the circuit C";

    // Create the inputs
    int NINPUTS = 3;
    Boolean* x = new_Boolean(false);
    Boolean* y = new_Boolean(false);
    Boolean* z = new_Boolean(false);
    Boolean** inputs = new_Boolean_array(NINPUTS);
    inputs[0] = x;
    inputs[1] = y;
    inputs[2] = z;

    // Create the outputs
    int NOUTPUTS = 1;
    Boolean* result = new_Boolean(false);
    Boolean** outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    // Create the gates
    int NGATES = 8;
    Gate* A1 = new_OrGate();
    Gate* A2 = new_Inverter();
    Gate* A3 = new_OrGate();
    Gate* A4 = new_Inverter();
    Gate* A5 = new_AndGate();
    Gate* A6 = new_OrGate();
    Gate* A7 = new_Inverter();
    Gate* A8 = new_AndGate();
    Gate** gates = new_Gate_array(NGATES);
    gates[0] = A1;
    gates[1] = A2;
    gates[2] = A3;
    gates[3] = A4;
    gates[4] = A5;
    gates[5] = A6;
    gates[6] = A7;
    gates[7] = A8;

    // Create the circuit
    Circuit *circuit = new_Circuit(title,
                                   NINPUTS, inputs,
                                   NOUTPUTS, outputs,
                                   NGATES, gates);

    // Connect the gates in the circuit
    // x or not y
    Circuit_connect(circuit, x, Gate_getInput(A1, 0));
    Circuit_connect(circuit, y, Gate_getInput(A2, 0));
    Boolean* not_y = Gate_getOutput(A2);
    Circuit_connect(circuit, not_y, Gate_getInput(A1, 1));
    Boolean* x_or_not_y = Gate_getOutput(A1);

    // y or not z
    Circuit_connect(circuit, y, Gate_getInput(A3, 0));
    Circuit_connect(circuit, z, Gate_getInput(A4, 0));
    Boolean* not_z = Gate_getOutput(A4);
    Circuit_connect(circuit, not_z, Gate_getInput(A3, 1));
    Boolean* y_or_not_z = Gate_getOutput(A3);

    // (x or not y) and (y or not z)
    Circuit_connect(circuit, x_or_not_y, Gate_getInput(A5, 0));
    Circuit_connect(circuit, y_or_not_z, Gate_getInput(A5, 1));
    Boolean* x_or_not_y_and_y_or_not_z = Gate_getOutput(A5);

    // z or not x
    Circuit_connect(circuit, z, Gate_getInput(A6, 0));
    Circuit_connect(circuit, x, Gate_getInput(A7, 0));
    Boolean* not_x = Gate_getOutput(A7);
    Circuit_connect(circuit, not_x, Gate_getInput(A6, 1));
    Boolean* z_or_not_x = Gate_getOutput(A6);

    // ((x or not y) and (y or not z)) and (z or not x)
    Circuit_connect(circuit, x_or_not_y_and_y_or_not_z, Gate_getInput(A8, 0));
    Circuit_connect(circuit, z_or_not_x, Gate_getInput(A8, 1));
    Boolean* x_or_not_y_and_y_or_not_z_and_z_or_not_x = Gate_getOutput(A8);

    Circuit_connect(circuit, x_or_not_y_and_y_or_not_z_and_z_or_not_x, result);

    // Done!
    return circuit;
}

int main(int argc, char **argv) {
//	Circuit* circuit = and3_Circuit();
//	Circuit_dump(circuit);
//	printf("\n");
//	printf("Testing: Some input(s) false: should be false\n");
//	test3In1Out(circuit, true, true, false);
//	printf("Testing: All inputs true: should be true\n");
//	test3In1Out(circuit, true, true, true);
//	printf("\nNote: Your program needs a function that tests ANY circuit on ALL possible\ncombinations of input values, in order from all false to all true, per the\nproject description.\n");
//	Circuit_free(circuit);

//  Test circuit A
    printf("Now begins to test circuit A: (x and y) or (not x)\n");
	Circuit* circuit1 = circuitA();
	Circuit_dump(circuit1);
	printf("\n");
	printf("Testing: x = true, y = true: should be true\n");
    test2In1Out(circuit1, true, true);
    printf("Testing: x = true, y = false: should be true\n");
    test2In1Out(circuit1, true, false);
    printf("Testing: x = false, y = true: should be false\n");
    test2In1Out(circuit1, false, true);
    printf("Testing: x = false, y = false: should be true\n");
    test2In1Out(circuit1, false, false);
	printf("\n");
	Circuit_free(circuit1);

    //  Test circuit B
    printf("Now begins to test circuit B: (x nor y) nor (x nor y)\n");
    Circuit* circuit2 = circuitB();
    Circuit_dump(circuit2);
    printf("\n");
    printf("Testing: x = true, y = true: should be true\n");
    test2In1Out(circuit2, true, true);
    printf("Testing: x = true, y = false: should be true\n");
    test2In1Out(circuit2, true, false);
    printf("Testing: x = false, y = true: should be true\n");
    test2In1Out(circuit2, false, true);
    printf("Testing: x = false, y = false: should be false\n");
    test2In1Out(circuit2, false, false);
    printf("\n");
    Circuit_free(circuit2);

    //  Test circuit C
    printf("Now begins to test circuit C: ((x or not y) and (y or not z)) and (z or not x)\n");
    Circuit* circuit3 = circuitC();
    Circuit_dump(circuit3);
    printf("\n");
    printf("Testing: x = true, y = true, z = true: should be true\n");
    test3In1Out(circuit3, true, true, true);
    printf("Testing: x = true, y = true, z = false: should be false\n");
    test3In1Out(circuit3, true, true, false);
    printf("Testing: x = true, y = false, z = true: should be false\n");
    test3In1Out(circuit3, true, false, true);
    printf("Testing: x = true, y = false, z = false: should be false\n");
    test3In1Out(circuit3, true, false, false);
    printf("Testing: x = false, y = true, z = true: should be false\n");
    test3In1Out(circuit3, false, true, true);
    printf("Testing: x = false, y = true, z = false: should be false\n");
    test3In1Out(circuit3, false, true, false);
    printf("Testing: x = false, y = false, z = true: should be false\n");
    test3In1Out(circuit3, false, false, true);
    printf("Testing: x = false, y = false, z = false: should be true\n");
    test3In1Out(circuit3, false, false, false);
    printf("\n");
    Circuit_free(circuit3);

}
