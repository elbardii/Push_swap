#!/bin/bash

# test_push_swap.sh - Automated testing script for 42 Push_swap project
# Created: April 18, 2025

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
RESET='\033[0m'

# Symbols for passed/failed tests
PASS="✅"
FAIL="❌"

# Counter for passed tests
PASSED=0
TOTAL=0

# Function to print section headers
print_header() {
    echo -e "\n${BLUE}===================================================${RESET}"
    echo -e "${BLUE}$1${RESET}"
    echo -e "${BLUE}===================================================${RESET}"
}

# Function to check if the program ran successfully
check_result() {
    if [ $1 -eq 0 ]; then
        echo -e "${GREEN}$PASS Test passed${RESET}"
        PASSED=$((PASSED+1))
    else
        echo -e "${RED}$FAIL Test failed${RESET}"
    fi
    TOTAL=$((TOTAL+1))
}

# Function to run leak check based on OS
check_leaks() {
    echo -e "${YELLOW}Testing for memory leaks:${RESET} $1"
    
    if command -v valgrind &> /dev/null; then
        # Linux: Use valgrind for leak detection
        valgrind --leak-check=full --error-exitcode=1 --quiet $1
        check_result $?
    elif command -v leaks &> /dev/null; then
        # macOS: Use leaks
        leaks -atExit -- $1
        # Check output of leaks manually
        echo -e "${YELLOW}Please check the leaks output above manually${RESET}"
        TOTAL=$((TOTAL+1))
    else
        echo -e "${RED}No leak checking tools found (valgrind or leaks)${RESET}"
    fi
}

# Function to count instructions
count_instructions() {
    local count=$(echo "$1" | wc -l)
    echo $count
}

# Function to evaluate performance based on instruction count
evaluate_performance() {
    local count=$1
    local threshold_5=$2
    local threshold_4=$3
    local threshold_3=$4
    local threshold_2=$5
    local threshold_1=$6

    if [ $count -lt $threshold_5 ]; then
        echo -e "${GREEN}Rating: 5/5 ($count instructions)${RESET}"
    elif [ $count -lt $threshold_4 ]; then
        echo -e "${GREEN}Rating: 4/5 ($count instructions)${RESET}"
    elif [ $count -lt $threshold_3 ]; then
        echo -e "${YELLOW}Rating: 3/5 ($count instructions)${RESET}"
    elif [ $count -lt $threshold_2 ]; then
        echo -e "${YELLOW}Rating: 2/5 ($count instructions)${RESET}"
    elif [ $count -lt $threshold_1 ]; then
        echo -e "${RED}Rating: 1/5 ($count instructions)${RESET}"
    else
        echo -e "${RED}Rating: 0/5 ($count instructions)${RESET}"
    fi
}

# Check if push_swap executable exists
if [ ! -f "./push_swap" ]; then
    echo -e "${RED}Error: push_swap executable not found${RESET}"
    echo -e "Make sure to compile your project first with 'make'"
    exit 1
fi

# Check if checker_OS exists
HAS_CHECKER=false
CHECKER_CMD="./checker_OS"
if [ -f "$CHECKER_CMD" ]; then
    HAS_CHECKER=true
else
    # Try to find in PATH
    if command -v checker_linux &> /dev/null; then
        CHECKER_CMD="checker_linux"
        HAS_CHECKER=true
    elif command -v checker_Mac &> /dev/null; then
        CHECKER_CMD="checker_Mac"
        HAS_CHECKER=true
    elif command -v checker &> /dev/null; then
        CHECKER_CMD="checker"
        HAS_CHECKER=true
    else
        echo -e "${YELLOW}Warning: checker program not found. Some tests will be limited.${RESET}"
    fi
fi

#----------------------------------------------------------------------------
# 1. MEMORY LEAK TESTS
#----------------------------------------------------------------------------
print_header "MEMORY LEAK TESTS"
check_leaks "./push_swap 1 2 3"

#----------------------------------------------------------------------------
# 2. ERROR MANAGEMENT TESTS
#----------------------------------------------------------------------------
print_header "ERROR MANAGEMENT TESTS"

# Test with non-numeric arguments
echo -e "${YELLOW}Testing with non-numeric arguments:${RESET} ./push_swap a b"
ERR_OUTPUT=$(./push_swap a b 2>&1 >/dev/null)
if [ "$ERR_OUTPUT" = "Error" ] || [ "$ERR_OUTPUT" = "Error\n" ]; then
    echo -e "${GREEN}$PASS Test passed${RESET}"
    PASSED=$((PASSED+1))
else
    echo -e "${RED}$FAIL Test failed - Expected 'Error', got: '$ERR_OUTPUT'${RESET}"
fi
TOTAL=$((TOTAL+1))

# Test with duplicate numbers
echo -e "${YELLOW}Testing with duplicate numbers:${RESET} ./push_swap 1 2 2"
ERR_OUTPUT=$(./push_swap 1 2 2 2>&1 >/dev/null)
if [ "$ERR_OUTPUT" = "Error" ] || [ "$ERR_OUTPUT" = "Error\n" ]; then
    echo -e "${GREEN}$PASS Test passed${RESET}"
    PASSED=$((PASSED+1))
else
    echo -e "${RED}$FAIL Test failed - Expected 'Error', got: '$ERR_OUTPUT'${RESET}"
fi
TOTAL=$((TOTAL+1))

# Test with overflow
echo -e "${YELLOW}Testing with INT_MAX+1:${RESET} ./push_swap 1 2147483648"
ERR_OUTPUT=$(./push_swap 1 2147483648 2>&1 >/dev/null)
if [ "$ERR_OUTPUT" = "Error" ] || [ "$ERR_OUTPUT" = "Error\n" ]; then
    echo -e "${GREEN}$PASS Test passed${RESET}"
    PASSED=$((PASSED+1))
else
    echo -e "${RED}$FAIL Test failed - Expected 'Error', got: '$ERR_OUTPUT'${RESET}"
fi
TOTAL=$((TOTAL+1))

# Test with INT_MIN-1
echo -e "${YELLOW}Testing with INT_MIN-1:${RESET} ./push_swap 1 -2147483649"
ERR_OUTPUT=$(./push_swap 1 -2147483649 2>&1 >/dev/null)
if [ "$ERR_OUTPUT" = "Error" ] || [ "$ERR_OUTPUT" = "Error\n" ]; then
    echo -e "${GREEN}$PASS Test passed${RESET}"
    PASSED=$((PASSED+1))
else
    echo -e "${RED}$FAIL Test failed - Expected 'Error', got: '$ERR_OUTPUT'${RESET}"
fi
TOTAL=$((TOTAL+1))

# Test with no arguments
echo -e "${YELLOW}Testing with no arguments:${RESET} ./push_swap"
OUTPUT=$(./push_swap 2>&1)
if [ -z "$OUTPUT" ]; then
    echo -e "${GREEN}$PASS Test passed${RESET}"
    PASSED=$((PASSED+1))
else
    echo -e "${RED}$FAIL Test failed - Expected no output, got: '$OUTPUT'${RESET}"
fi
TOTAL=$((TOTAL+1))

#----------------------------------------------------------------------------
# 3. IDENTITY TESTS (ALREADY SORTED)
#----------------------------------------------------------------------------
print_header "IDENTITY TESTS (ALREADY SORTED)"

# Test with single number
echo -e "${YELLOW}Testing with single number:${RESET} ./push_swap 42"
OUTPUT=$(./push_swap 42)
if [ -z "$OUTPUT" ]; then
    echo -e "${GREEN}$PASS Test passed${RESET}"
    PASSED=$((PASSED+1))
else
    echo -e "${RED}$FAIL Test failed - Expected no output, got: '$OUTPUT'${RESET}"
fi
TOTAL=$((TOTAL+1))

# Test with sorted pair
echo -e "${YELLOW}Testing with sorted pair:${RESET} ./push_swap 2 3"
OUTPUT=$(./push_swap 2 3)
if [ -z "$OUTPUT" ]; then
    echo -e "${GREEN}$PASS Test passed${RESET}"
    PASSED=$((PASSED+1))
else
    echo -e "${RED}$FAIL Test failed - Expected no output, got: '$OUTPUT'${RESET}"
fi
TOTAL=$((TOTAL+1))

# Test with sorted small list
echo -e "${YELLOW}Testing with sorted small list:${RESET} ./push_swap 0 1 2 3"
OUTPUT=$(./push_swap 0 1 2 3)
if [ -z "$OUTPUT" ]; then
    echo -e "${GREEN}$PASS Test passed${RESET}"
    PASSED=$((PASSED+1))
else
    echo -e "${RED}$FAIL Test failed - Expected no output, got: '$OUTPUT'${RESET}"
fi
TOTAL=$((TOTAL+1))

# Test with sorted large list
echo -e "${YELLOW}Testing with sorted large list:${RESET} ./push_swap 0 1 2 3 4 5 6 7 8 9"
OUTPUT=$(./push_swap 0 1 2 3 4 5 6 7 8 9)
if [ -z "$OUTPUT" ]; then
    echo -e "${GREEN}$PASS Test passed${RESET}"
    PASSED=$((PASSED+1))
else
    echo -e "${RED}$FAIL Test failed - Expected no output, got: '$OUTPUT'${RESET}"
fi
TOTAL=$((TOTAL+1))

#----------------------------------------------------------------------------
# 4. SIMPLE VERSION TESTS (3 NUMBERS)
#----------------------------------------------------------------------------
print_header "SIMPLE VERSION TESTS (3 NUMBERS)"

# Test with 3 numbers in reverse order
echo -e "${YELLOW}Testing with 3 numbers in reverse order:${RESET} ./push_swap 2 1 0"
OPERATIONS=$(./push_swap 2 1 0)
INSTR_COUNT=$(count_instructions "$OPERATIONS")

echo -e "Instruction count: ${YELLOW}$INSTR_COUNT${RESET}"
if [ $INSTR_COUNT -le 3 ]; then
    echo -e "${GREEN}$PASS Test passed${RESET}"
    PASSED=$((PASSED+1))
else
    echo -e "${RED}$FAIL Test failed - Expected ≤3 instructions, got: $INSTR_COUNT${RESET}"
fi
TOTAL=$((TOTAL+1))

if $HAS_CHECKER; then
    ARG="2 1 0"
    echo -e "${YELLOW}Testing with checker:${RESET} ARG=\"$ARG\"; ./push_swap \$ARG | $CHECKER_CMD \$ARG"
    RESULT=$(./push_swap $ARG | $CHECKER_CMD $ARG)
    if [ "$RESULT" = "OK" ]; then
        echo -e "${GREEN}$PASS Checker test passed${RESET}"
        PASSED=$((PASSED+1))
    else
        echo -e "${RED}$FAIL Checker test failed - Expected 'OK', got: '$RESULT'${RESET}"
    fi
    TOTAL=$((TOTAL+1))
fi

# Test with 3 random numbers
if command -v shuf &> /dev/null; then
    ARG=$(shuf -i 0-3 -n 3 | tr "\n" " ")
    echo -e "${YELLOW}Testing with 3 random numbers:${RESET} ./push_swap $ARG"
    OPERATIONS=$(./push_swap $ARG)
    INSTR_COUNT=$(count_instructions "$OPERATIONS")

    echo -e "Instruction count: ${YELLOW}$INSTR_COUNT${RESET}"
    if [ $INSTR_COUNT -le 3 ]; then
        echo -e "${GREEN}$PASS Test passed${RESET}"
        PASSED=$((PASSED+1))
    else
        echo -e "${RED}$FAIL Test failed - Expected ≤3 instructions, got: $INSTR_COUNT${RESET}"
    fi
    TOTAL=$((TOTAL+1))

    if $HAS_CHECKER; then
        echo -e "${YELLOW}Testing with checker:${RESET} ARG=\"$ARG\"; ./push_swap \$ARG | $CHECKER_CMD \$ARG"
        RESULT=$(./push_swap $ARG | $CHECKER_CMD $ARG)
        if [ "$RESULT" = "OK" ]; then
            echo -e "${GREEN}$PASS Checker test passed${RESET}"
            PASSED=$((PASSED+1))
        else
            echo -e "${RED}$FAIL Checker test failed - Expected 'OK', got: '$RESULT'${RESET}"
        fi
        TOTAL=$((TOTAL+1))
    fi
else
    echo -e "${YELLOW}Warning: 'shuf' command not found. Skipping random number tests.${RESET}"
fi

#----------------------------------------------------------------------------
# 5. SIMPLE VERSION WITH 5 NUMBERS
#----------------------------------------------------------------------------
print_header "SIMPLE VERSION TESTS (5 NUMBERS)"

# Test with 5 specific numbers
ARG="1 5 2 4 3"
echo -e "${YELLOW}Testing with 5 specific numbers:${RESET} ./push_swap $ARG"
OPERATIONS=$(./push_swap $ARG)
INSTR_COUNT=$(count_instructions "$OPERATIONS")

echo -e "Instruction count: ${YELLOW}$INSTR_COUNT${RESET}"
if [ $INSTR_COUNT -le 12 ]; then
    echo -e "${GREEN}$PASS Test passed - $INSTR_COUNT instructions (ideal: 8)${RESET}"
    PASSED=$((PASSED+1))
else
    echo -e "${RED}$FAIL Test failed - Expected ≤12 instructions, got: $INSTR_COUNT${RESET}"
fi
TOTAL=$((TOTAL+1))

if $HAS_CHECKER; then
    echo -e "${YELLOW}Testing with checker:${RESET} ARG=\"$ARG\"; ./push_swap \$ARG | $CHECKER_CMD \$ARG"
    RESULT=$(./push_swap $ARG | $CHECKER_CMD $ARG)
    if [ "$RESULT" = "OK" ]; then
        echo -e "${GREEN}$PASS Checker test passed${RESET}"
        PASSED=$((PASSED+1))
    else
        echo -e "${RED}$FAIL Checker test failed - Expected 'OK', got: '$RESULT'${RESET}"
    fi
    TOTAL=$((TOTAL+1))
fi

# Test with 5 random numbers
if command -v shuf &> /dev/null; then
    ARG=$(shuf -i 0-100 -n 5 | tr "\n" " ")
    echo -e "${YELLOW}Testing with 5 random numbers:${RESET} ./push_swap $ARG"
    OPERATIONS=$(./push_swap $ARG)
    INSTR_COUNT=$(count_instructions "$OPERATIONS")

    echo -e "Instruction count: ${YELLOW}$INSTR_COUNT${RESET}"
    if [ $INSTR_COUNT -le 12 ]; then
        echo -e "${GREEN}$PASS Test passed - $INSTR_COUNT instructions (ideal: 8)${RESET}"
        PASSED=$((PASSED+1))
    else
        echo -e "${RED}$FAIL Test failed - Expected ≤12 instructions, got: $INSTR_COUNT${RESET}"
    fi
    TOTAL=$((TOTAL+1))

    if $HAS_CHECKER; then
        echo -e "${YELLOW}Testing with checker:${RESET} ARG=\"$ARG\"; ./push_swap \$ARG | $CHECKER_CMD \$ARG"
        RESULT=$(./push_swap $ARG | $CHECKER_CMD $ARG)
        if [ "$RESULT" = "OK" ]; then
            echo -e "${GREEN}$PASS Checker test passed${RESET}"
            PASSED=$((PASSED+1))
        else
            echo -e "${RED}$FAIL Checker test failed - Expected 'OK', got: '$RESULT'${RESET}"
        fi
        TOTAL=$((TOTAL+1))
    fi
else
    echo -e "${YELLOW}Warning: 'shuf' command not found. Skipping random number tests.${RESET}"
fi

#----------------------------------------------------------------------------
# 6. MIDDLE VERSION (100 NUMBERS)
#----------------------------------------------------------------------------
print_header "MIDDLE VERSION TESTS (100 NUMBERS)"

if command -v shuf &> /dev/null; then
    ARG=$(shuf -i 0-999 -n 100 | tr "\n" " ")
    echo -e "${YELLOW}Testing with 100 random numbers${RESET}"
    OPERATIONS=$(./push_swap $ARG)
    INSTR_COUNT=$(count_instructions "$OPERATIONS")

    echo -e "Instruction count: ${YELLOW}$INSTR_COUNT${RESET}"
    evaluate_performance $INSTR_COUNT 700 900 1100 1300 1500
    
    if [ $INSTR_COUNT -lt 1500 ]; then
        PASSED=$((PASSED+1))
    fi
    TOTAL=$((TOTAL+1))

    if $HAS_CHECKER; then
        echo -e "${YELLOW}Testing with checker:${RESET} ./push_swap \$ARG | $CHECKER_CMD \$ARG"
        RESULT=$(./push_swap $ARG | $CHECKER_CMD $ARG)
        if [ "$RESULT" = "OK" ]; then
            echo -e "${GREEN}$PASS Checker test passed${RESET}"
            PASSED=$((PASSED+1))
        else
            echo -e "${RED}$FAIL Checker test failed - Expected 'OK', got: '$RESULT'${RESET}"
        fi
        TOTAL=$((TOTAL+1))
    fi
else
    echo -e "${YELLOW}Warning: 'shuf' command not found. Skipping random number tests.${RESET}"
fi

#----------------------------------------------------------------------------
# 7. ADVANCED VERSION (500 NUMBERS)
#----------------------------------------------------------------------------
print_header "ADVANCED VERSION TESTS (500 NUMBERS)"

if command -v shuf &> /dev/null; then
    ARG=$(shuf -i 0-999 -n 500 | tr "\n" " ")
    echo -e "${YELLOW}Testing with 500 random numbers${RESET}"
    OPERATIONS=$(./push_swap $ARG)
    INSTR_COUNT=$(count_instructions "$OPERATIONS")

    echo -e "Instruction count: ${YELLOW}$INSTR_COUNT${RESET}"
    evaluate_performance $INSTR_COUNT 5500 7000 8500 10000 11500
    
    if [ $INSTR_COUNT -lt 11500 ]; then
        PASSED=$((PASSED+1))
    fi
    TOTAL=$((TOTAL+1))

    if $HAS_CHECKER; then
        echo -e "${YELLOW}Testing with checker:${RESET} ./push_swap \$ARG | $CHECKER_CMD \$ARG"
        RESULT=$(./push_swap $ARG | $CHECKER_CMD $ARG)
        if [ "$RESULT" = "OK" ]; then
            echo -e "${GREEN}$PASS Checker test passed${RESET}"
            PASSED=$((PASSED+1))
        else
            echo -e "${RED}$FAIL Checker test failed - Expected 'OK', got: '$RESULT'${RESET}"
        fi
        TOTAL=$((TOTAL+1))
    fi
else
    echo -e "${YELLOW}Warning: 'shuf' command not found. Skipping random number tests.${RESET}"
fi

#----------------------------------------------------------------------------
# FINAL RESULTS
#----------------------------------------------------------------------------
print_header "TEST RESULTS"
echo -e "Tests passed: ${GREEN}$PASSED${RESET}/$TOTAL"

if [ $PASSED -eq $TOTAL ]; then
    echo -e "${GREEN}All tests passed! Your push_swap is working correctly.${RESET}"
else
    FAILED=$((TOTAL-PASSED))
    echo -e "${RED}$FAILED tests failed. Please check the output above for details.${RESET}"
fi

echo -e "\nNOTE: This script is meant to help you prepare for evaluation."
echo -e "Your final grade will depend on the actual evaluation criteria."