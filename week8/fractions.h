//
// DO NOT CHANGE THIS FILE
//
// You do not submit this file. This file is not marked.
// If you think you need to change this file you have
// misunderstood the exercise - ask in the course forum.
//
// Week 8 Lab Exercise: Fractions
// fractions.h
//
// You must not change this file.
//
// THIS FILE WILL NOT BE MARKED
//
// Details the functions required.
//

#ifndef _FRACTIONS_H_
#define _FRACTIONS_H_


// `struct fraction` is how we hold the information of a fraction.
//
// `top` refers to the number on the top part of the fraction.
// This is also referred to as the numerator.
//
// `bottom` refers to the number on the bottom part of the fraction.
// This is also referred to as the denominator.
//
// An example fraction is 1 / 2. If this is stored in a `struct
// fraction`, `top` will be 1 and `bottom` will be 2.
struct fraction {
    int top;
    int bottom;
};

// Takes a fraction and converts it into its double form.
//
// For example, if the function was passed in a struct fraction with top 1
// and bottom 2, the function will return 0.5.
//
// `convert` will be passed in the parameter:
// - `frac` -- a struct fraction.
// 
// `convert` will return the double version of the fraction.
//
// ASSUMPTIONS:
// - `frac.bottom` will never be 0.
// - `frac` will be a valid fraction.
double convert(struct fraction frac);

// Adds two fractions together and returns their result.
//
// To add fractions, we use the following formula.
// a   c   ad + bc
// - + - = ------
// b   d     bd
//
// For example, if the function was passed in the fractions 1/2 and 1/3,
// the function will return the fraction 5/6.
//
// You will also be required to simplify if possible. For instance, if the 
// function was passed in the fractions 1/2 and 1/2, the function will return 
// the fraction 1/1. Returning 2/2 or 4/4 or any other version is not the
// expected behaviour.
//
// `add` will be passed in the parameters:
// - `first` -- a struct fraction.
// - `second` -- a strut fraction.
// 
// `add` will return the result of adding the two fractions together.
//
// ASSUMPTIONS: 
// - `first.bottom` and `second.bottom` will never be 0.
// - `first` and `second` will be valid fractions.
// - `add` will never be passed in negative fractions.
struct fraction add(struct fraction first, struct fraction second);


#endif // _FRACTIONS_H_