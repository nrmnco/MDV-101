# MDV-101

This repository contains lab work completed for MDV-101, a digital design and hardware description course. The progression covers combinational logic, sequential circuits, Verilog-based simulation with Verilator, and culminates in a multi-week implementation of the Bitty Processor, a custom 16-bit educational CPU.

## Repository Structure

```
MDV-101/
├── Week1/
│   ├── Lab1/   -- 2-to-1 multiplexer (Logisim)
│   ├── Lab2/   -- Boolean logic circuits with test vectors (Logisim)
│   ├── Lab3/   -- Priority encoder (Logisim)
│   └── Lab4/   -- Arithmetic Logic Unit (Logisim)
├── Week2/
│   └── Lab5/   -- Sequential circuit design (Logisim)
├── week3/
│   ├── lab6/   -- 9-input priority encoder (Verilog)
│   ├── lab7/   -- AND gate with Verilator testbench and VCD waveform
│   └── lab8/   -- Fibonacci sequence generator (Verilog, sequential)
├── week4/
│   ├── lab9/   -- Bitty Processor initial RTL + testbenches
│   └── lab10/  -- Bitty Processor iteration + traffic light FSM prelab
├── week5/
│   └── (root)  -- Bitty Processor full RTL with Verilator build tooling
└── week6/
    └── lab12/  -- Bitty Processor final iteration
```

## Labs Overview

### Week 1 - Combinational Logic (Logisim)

| Lab | Topic |
|-----|-------|
| Lab 1 | 2-to-1 multiplexer |
| Lab 2 | Boolean expression circuits with truth table test vectors |
| Lab 3 | 9-input priority encoder |
| Lab 4 | Arithmetic Logic Unit |

### Week 2 - Sequential Logic (Logisim)

| Lab | Topic |
|-----|-------|
| Lab 5 | Sequential circuit design |

### Week 3 - Verilog and Simulation

| Lab | Topic |
|-----|-------|
| Lab 6 | 9-input priority encoder in Verilog |
| Lab 7 | AND gate simulation with Verilator and VCD waveform generation |
| Lab 8 | 32-bit Fibonacci sequence generator (clocked, with reset and enable) |

### Week 4 - FSMs and Processor Foundations

| Lab | Topic |
|-----|-------|
| Lab 9  | Bitty Processor RTL v1 with unit testbenches |
| Lab 10 | Bitty Processor RTL v2 + traffic light FSM (prelab) |

### Week 5 - Bitty Processor

Full RTL implementation of the Bitty Processor with Verilator-based simulation infrastructure.

### Week 6

| Lab | Topic |
|-----|-------|
| Lab 12 | Bitty Processor final RTL iteration |

---

## The Bitty Processor

The Bitty Processor is a custom 16-bit processor designed for educational purposes. It executes single instructions in a 4-stage pipeline driven by a finite state machine control unit.

### Architecture

```
Instruction Register (reg_instr)
        |
   Control Unit (FSM)
        |
  +-----------+-----------+
  |           |           |
 MUX    Source Reg (S)  GPRs (R0-R7)
  |           |
 ALU <--------+
  |
Carry Reg (C) --> GPRs (R0-R7)
```

### Modules

| Module | File | Description |
|--------|------|-------------|
| `bitty_core` | `rtl/bitty_core.v` | Top-level processor module |
| `control_unit` | `rtl/control_unit.v` | 4-state FSM, decodes instruction and drives enables |
| `alu` | `rtl/alu.v` | Dispatches to arithmetic or logic unit based on mode |
| `arithmetic_unit` | `rtl/arithmetic_unit.v` | Arithmetic operations (add, subtract, compare) |
| `logic_unit` | `rtl/logic_unit.v` | Bitwise logical operations |
| `mux` | `rtl/mux.v` | 8-to-1 multiplexer for register source selection |
| `register` | `rtl/register.v` | 16-bit clocked register with synchronous enable |

### Instruction Encoding

| Bits | Field | Description |
|------|-------|-------------|
| `[15:13]` | Destination / Source A | Register select (R0-R7) |
| `[12:10]` | Source B | Register select for second operand |
| `[6:3]` | ALU select | Operation select |
| `[2]` | ALU mode | `0` = arithmetic, `1` = logic |

### Execution Pipeline (FSM States)

| State | Action |
|-------|--------|
| STATE0 | Latch instruction into `reg_instr` |
| STATE1 | Latch source operand A into `reg_s` via MUX |
| STATE2 | Execute ALU operation, latch result into `reg_c` |
| STATE3 | Write result from `reg_c` back to destination register, assert `done` |

---

## Tooling

### bitty_run.py

A Python utility script that wraps Verilator compilation for the Bitty Processor. It is located in the root of each Bitty Processor lab directory.

**Usage:**

```bash
# List all modules in the design
python3 bitty_run.py -l

# Compile all modules
python3 bitty_run.py -a

# Compile a single module
python3 bitty_run.py -s <module_name>

# Compile with VCD waveform generation
python3 bitty_run.py -a -w
python3 bitty_run.py -s <module_name> -w

# Clean generated Verilator artifacts
python3 bitty_run.py -c
```

**Available modules:** `bitty_core`, `alu`, `arithmetic_unit`, `control_unit`, `logic_unit`, `mux`, `register`

### Test Directory Structure

Each module under `test/` has a corresponding C++ testbench:

```
test/
├── bitty_core/   bitty_core_tb.cpp
├── alu/          alu_tb.cpp
├── control_unit/ control_unit_tb.cpp
├── mux/          mux_tb.cpp
└── register/     register_tb.cpp
```

---

## Prerequisites

| Tool | Purpose |
|------|---------|
| [Logisim Evolution](https://github.com/logisim-evolution/logisim-evolution) | Open and simulate `.circ` files (Weeks 1-2) |
| [Verilator](https://verilator.org) | HDL simulation and linting (Weeks 3-6) |
| [GTKWave](https://gtkwave.sourceforge.net) | View `.vcd` waveform files |
| Python 3 | Run `bitty_run.py` build utility |
| Make / GCC | Build Verilator-generated C++ |

### Installing Verilator (Ubuntu/Debian)

```bash
sudo apt install verilator
```
