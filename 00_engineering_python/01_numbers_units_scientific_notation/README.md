[![Notebook CI](https://github.com/hunkarsuci/rf-space-systems-lab/actions/workflows/notebook-ci.yml/badge.svg?branch=main)](https://github.com/hunkarsuci/rf-space-systems-lab/actions/workflows/notebook-ci.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/hunkarsuci/rf-space-systems-lab/blob/main/LICENSE)

# Numbers, Units, and Scientific Notation

This is the first lesson in the **Engineering Python** curriculum.

The lesson introduces basic Python numerical operations through RF and space-systems engineering quantities such as frequency, time, distance, power, propagation speed, and wavelength.

---

## Learning objectives

After completing this lesson, I should be able to:

* Distinguish between integers and floating-point numbers.
* Store engineering quantities in Python variables.
* Perform basic arithmetic calculations.
* Write large and small values using scientific notation.
* Convert between common SI units.
* Calculate signal period from frequency.
* Calculate free-space wavelength from frequency.
* State the unit associated with every engineering result.
* Compare a Python result with a hand calculation.
* Explain why dimensional consistency is necessary.

---

## Python concepts

This lesson introduces:

* Integers
* Floating-point numbers
* Variables
* Assignment
* Arithmetic operators
* Operator precedence
* Scientific notation
* Comments
* Basic printed output
* Descriptive variable names

This lesson does not yet use:

* Functions
* Conditions
* Loops
* NumPy
* Matplotlib
* Classes
* Python packages
* Automated tests

These concepts will be introduced gradually in later lessons.

---

## Engineering concepts

This lesson introduces:

* Physical quantities
* Numerical values
* Units
* SI prefixes
* Frequency
* Period
* Propagation speed
* Wavelength
* Unit conversion
* Dimensional consistency

---

## Physical quantities and units

An engineering quantity consists of a numerical value and a unit.

For example:

```text
2.4 GHz
```

contains:

* Numerical value: `2.4`
* Unit: `GHz`
* Physical quantity: frequency

A number without a unit is often incomplete or ambiguous.

For example, the value:

```text
10
```

could mean:

* 10 hertz
* 10 seconds
* 10 metres
* 10 watts
* 10 decibels

For this reason, variable names should communicate the expected unit.

```python
frequency_hz = 2.4e9
distance_m = 1_000.0
power_w = 5.0
time_s = 0.25
```

The suffixes `_hz`, `_m`, `_w`, and `_s` indicate the units associated with the variables.

---

## SI prefixes

Engineering calculations frequently use SI prefixes.

| Prefix | Symbol |     Scale | Python notation |
| ------ | -----: | --------: | --------------: |
| giga   |      G |    $10^9$ |           `1e9` |
| mega   |      M |    $10^6$ |           `1e6` |
| kilo   |      k |    $10^3$ |           `1e3` |
| milli  |      m | $10^{-3}$ |          `1e-3` |
| micro  |      µ | $10^{-6}$ |          `1e-6` |
| nano   |      n | $10^{-9}$ |          `1e-9` |

Capitalization matters.

For example:

* `MHz` means megahertz.
* `mHz` means millihertz.

These two units differ by a factor of $10^9$.

---

## Scientific notation in Python

Engineering values can be extremely large or extremely small.

Python uses `e` notation to represent powers of ten.

```python
one_thousand = 1e3
one_million = 1e6
one_billion = 1e9

one_thousandth = 1e-3
one_millionth = 1e-6
one_billionth = 1e-9
```

The expression:

```python
2.4e9
```

represents:

$$
2.4 \times 10^9
$$

Similarly:

```python
1e-6
```

represents:

$$
1 \times 10^{-6}
$$

---

## Digit separators

Python allows underscores inside long numerical values.

The following two values are identical:

```python
2400000000
2_400_000_000
```

Digit separators improve readability but do not change the numerical value.

For engineering code, the second form is often easier to inspect.

---

## Frequency

Frequency describes the number of cycles completed per second.

The SI unit of frequency is the hertz:

$$
1\ \text{Hz} = 1\ \text{cycle per second}
$$

Common RF frequency units include:

| Unit  | Equivalent value |
| ----- | ---------------: |
| 1 kHz |        $10^3$ Hz |
| 1 MHz |        $10^6$ Hz |
| 1 GHz |        $10^9$ Hz |

For example:

$$
2.4\ \text{GHz}
===============

2.4 \times 10^9\ \text{Hz}
$$

In Python:

```python
frequency_ghz = 2.4
frequency_hz = frequency_ghz * 1e9
```

---

## Signal period

The period of a signal is the time required to complete one cycle.

Period and frequency are related by:

$$
T = \frac{1}{f}
$$

where:

* $T$ is the period in seconds
* $f$ is the frequency in hertz

For a signal with a frequency of $1\ \text{MHz}$:

$$
f = 1 \times 10^6\ \text{Hz}
$$

Therefore:

$$
T
=

# \frac{1}{1 \times 10^6}

1 \times 10^{-6}\ \text{s}
$$

The period is:

$$
T = 1\ \mu\text{s}
$$

In Python:

```python
frequency_hz = 1e6
period_s = 1 / frequency_hz
```

---

## Dimensional check for period

A dimensional check confirms that the equation produces the expected unit.

Frequency has units of inverse seconds:

$$
[f] = \text{s}^{-1}
$$

Therefore:

$$
[T]
===

# \frac{1}{\text{s}^{-1}}

\text{s}
$$

The result correctly has units of time.

---

## Free-space wavelength

Wavelength is the physical distance occupied by one complete cycle of a wave.

For an electromagnetic wave travelling through vacuum:

$$
\lambda = \frac{c}{f}
$$

where:

* $\lambda$ is wavelength in metres
* $c$ is propagation speed in metres per second
* $f$ is frequency in hertz

The exact defined value of the speed of light in vacuum is:

$$
c = 299,792,458\ \text{m/s}
$$

In Python:

```python
speed_of_light_m_per_s = 299_792_458.0
frequency_hz = 2.4e9

wavelength_m = speed_of_light_m_per_s / frequency_hz
```

---

## Dimensional check for wavelength

The units of propagation speed are metres per second:

$$
[c] = \frac{\text{m}}{\text{s}}
$$

The units of frequency are inverse seconds:

$$
[f] = \text{s}^{-1}
$$

Therefore:

$$
[\lambda]
=========

# \frac{\text{m/s}}{\text{s}^{-1}}

\text{m}
$$

The calculated result correctly has units of distance.

---

## Hand calculation

Calculate the wavelength of a $2.4\ \text{GHz}$ signal.

First convert the frequency to hertz:

$$
f = 2.4 \times 10^9\ \text{Hz}
$$

Use the approximate value:

$$
c \approx 3.0 \times 10^8\ \text{m/s}
$$

Apply the wavelength equation:

$$
\lambda = \frac{c}{f}
$$

Substitute the values:

$$
\lambda
=======

\frac{3.0 \times 10^8}
{2.4 \times 10^9}
$$

Therefore:

$$
\lambda = 0.125\ \text{m}
$$

Convert metres to centimetres:

$$
0.125\ \text{m} = 12.5\ \text{cm}
$$

The approximate wavelength of a $2.4\ \text{GHz}$ signal is therefore:

$$
\boxed{\lambda \approx 0.125\ \text{m}}
$$

---

## Relationship between frequency and wavelength

Wavelength is inversely proportional to frequency:

$$
\lambda \propto \frac{1}{f}
$$

This means:

* Doubling frequency halves wavelength.
* Multiplying frequency by 10 divides wavelength by 10.
* Halving frequency doubles wavelength.
* Dividing frequency by 10 multiplies wavelength by 10.

This relationship is important in:

* Antenna design
* RF propagation
* Radar
* Satellite communications
* Satellite navigation
* Waveguides
* Transmission lines
* Remote sensing

---

## Lesson files

The lesson directory should contain:

```text
01_numbers_units_scientific_notation/
├── README.md
└── lesson.ipynb
```

The `README.md` file explains the lesson scope and theory.

The `lesson.ipynb` notebook contains the Python calculations, exercises, experiments, and engineering conclusions.

---

## How to run the lesson

Open PowerShell in the repository root and start JupyterLab:

```powershell
jupyter lab
```

In JupyterLab, navigate to:

```text
00_engineering_python/
└── 01_numbers_units_scientific_notation/
    └── lesson.ipynb
```

Run the notebook cells from top to bottom.

Before committing the notebook, use:

```text
Kernel → Restart Kernel and Run All Cells
```

This confirms that the notebook works from a clean state.

---

## Engineering rules for this lesson

1. Every engineering value must have a stated unit.
2. Variables should identify their expected units.
3. Frequencies must be converted to hertz before using SI equations.
4. Distances must be converted to metres before using SI equations.
5. Hand calculations should be completed before or alongside Python calculations.
6. Results should be checked for physical reasonableness.
7. Dimensional consistency should be verified.
8. The notebook should run from beginning to end without errors.

---

## Exercises

The notebook includes exercises involving:

1. Conversion between GHz, MHz, and Hz
2. Conversion between kilometres and metres
3. Signal-period calculation
4. Free-space wavelength calculation
5. GPS L1 wavelength calculation
6. Comparison of wavelengths at different frequencies
7. Identification of unit-consistency errors
8. Written engineering conclusions

---

## Completion checklist

* [ ] I ran every notebook cell successfully.
* [ ] I understand the difference between integers and floating-point numbers.
* [ ] I can create variables with descriptive names.
* [ ] I can write values using scientific notation.
* [ ] I can convert GHz and MHz to Hz.
* [ ] I can convert kilometres to metres.
* [ ] I can calculate period from frequency.
* [ ] I can calculate wavelength from frequency.
* [ ] I state units with every engineering result.
* [ ] I completed at least one hand calculation.
* [ ] I checked dimensional consistency.
* [ ] I completed the notebook exercises.
* [ ] I wrote the engineering conclusions in my own words.
* [ ] I restarted the notebook kernel and ran all cells.
* [ ] I reviewed the repository changes using `git status`.

---

## Expected engineering conclusions

After completing the lesson, I should understand that:

* Scientific notation provides a practical way to represent engineering values.
* A numerical value without a unit can be ambiguous.
* Unit conversion must occur before values are used in equations.
* Signal period is inversely proportional to frequency.
* Wavelength is inversely proportional to frequency.
* Higher-frequency signals have shorter wavelengths.
* Dimensional analysis helps identify calculation errors.
* Python can reproduce and verify hand-worked engineering calculations.

---

## Next lesson

The next Engineering Python lesson will introduce variables, expressions, numeric types, formatted output, and floating-point behavior in greater depth.
