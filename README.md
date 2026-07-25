[![Notebook CI](https://github.com/hunkarsuci/rf-space-systems-lab/actions/workflows/notebook-ci.yml/badge.svg?branch=main)](https://github.com/hunkarsuci/rf-space-systems-lab/actions/workflows/notebook-ci.yml)

# RF Space Systems Lab

A structured Python learning and engineering laboratory covering:

- RF engineering
- Signals and digital signal processing
- Antennas and propagation
- Radar
- Orbital mechanics
- Satellite communications
- Satellite navigation
- Integrated RF and space-system simulations

This repository documents the progression from engineering fundamentals to reusable, tested simulation software.

> **Repository principle:** notebooks explain and experiment, Python modules implement reusable engineering logic, and tests verify correctness.

---

## Project objectives

The project is designed to develop both theoretical understanding and practical engineering capability.

Each major topic should include:

1. Mathematical derivation
2. Physical interpretation
3. Units and dimensional analysis
4. Hand-worked examples
5. Python implementation
6. Numerical experiments
7. Visualization
8. Verification against known results
9. Automated tests
10. Assumptions, limitations, and engineering discussion
11. Technical references
12. A final design or simulation project

The target is graduate-level technical depth and disciplined software-development practice. This is an independent learning project, not an accredited degree program.

---

## Learning sequence

```text
Engineering Python
        ↓
Engineering Mathematics
        ↓
Signals and Systems
        ↓
RF Fundamentals
        ↓
Digital Signal Processing
        ↓
Antennas and Propagation
        ↓
 ┌──────────────┬───────────────────┬──────────────────┐
 Radar     Orbital Mechanics     Satellite Systems
                                      ├─ SatCom
                                      └─ SatNav
        ↓
Integrated RF and Space Systems
```

Recommended order:

1. Engineering Python
2. Engineering mathematics
3. Signals and systems
4. RF fundamentals
5. Digital signal processing
6. Antennas and propagation
7. Radar
8. Orbital mechanics
9. Satellite communications
10. Satellite navigation
11. Integrated systems

---

## Repository structure

The repository will grow incrementally. New lesson directories should be added when work on them begins rather than creating many empty folders in advance.

```text
rf-space-systems-lab/
├── README.md
├── ROADMAP.md
├── CONTRIBUTING.md
├── pyproject.toml
├── .gitignore
│
├── 00_engineering_python/
├── 01_engineering_mathematics/
├── 02_signals_and_systems/
├── 03_rf_fundamentals/
├── 04_digital_signal_processing/
├── 05_antennas_and_propagation/
├── 06_radar/
├── 07_orbital_mechanics/
├── 08_satellite_communications/
├── 09_satellite_navigation/
├── 10_integrated_systems/
│
├── projects/
├── src/
│   └── rf_space_systems/
├── tests/
├── data/
├── figures/
└── references/
```

See [ROADMAP.md](ROADMAP.md) for the planned curriculum and project milestones.

---

## Lesson standard

Every lesson should follow a consistent engineering structure.

### 1. Learning objectives

State what the learner should be able to explain, calculate, implement, test, and interpret.

### 2. Theory

Introduce the physical model and derive the relevant equations. Define every symbol and unit.

For example:

$$
T = \frac{1}{f}
$$

$$
\lambda = \frac{c}{f}
$$

where:

- $T$ is period in seconds
- $f$ is frequency in hertz
- $\lambda$ is wavelength in metres
- $c$ is propagation speed in metres per second

### 3. Hand calculation

Complete at least one numerical example before writing code.

### 4. Python implementation

Start with a clear implementation in the lesson notebook. Move stable and reusable functions into:

```text
src/rf_space_systems/
```

### 5. Visualization

Plot relationships that improve engineering understanding, such as:

- Wavelength versus frequency
- Noise power versus bandwidth
- Free-space path loss versus distance
- Radar received power versus range
- Link margin versus elevation angle
- GNSS geometry versus positioning error

### 6. Engineering experiments

Vary parameters, predict the effect, and compare the prediction with the computed result.

### 7. Verification

Use assertions initially and `pytest` as reusable modules develop.

```python
from rf_space_systems.rf import frequency_to_wavelength

assert frequency_to_wavelength(299_792_458.0) == 1.0
```

### 8. Engineering conclusions

Summarize the principal relationships, assumptions, sensitivities, and practical implications.

---

## Software architecture

The project separates explanation, reusable implementation, and verification.

```text
Lesson notebooks
    Explain theory, derivations, examples, and experiments

src/rf_space_systems/
    Contains reusable engineering functions and simulation components

tests/
    Verifies numerical behavior, units, limits, and reference cases
```

Example:

```text
03_rf_fundamentals/03_db_dbm_dbw/lesson.ipynb
src/rf_space_systems/units.py
tests/test_units.py
```

---

## Initial lesson

The first planned lesson is:

```text
00_engineering_python/
└── 01_numbers_units_scientific_notation/
    └── lesson.ipynb
```

It will introduce Python numeric fundamentals through:

- Frequency
- Period
- Distance
- Wavelength
- Time
- Power
- Scientific notation
- SI prefixes
- Unit conversion

---

## Planned capstone projects

```text
projects/
├── project01_rf_calculator/
├── project02_signal_processing_lab/
├── project03_antenna_propagation_tool/
├── project04_radar_simulator/
├── project05_orbit_pass_predictor/
├── project06_satcom_link_designer/
└── project07_gnss_receiver_simulator/
```

Mature capstones may later become independent portfolio repositories:

- `rf-link-budget-tool`
- `radar-range-doppler-simulator`
- `satellite-pass-predictor`
- `satcom-link-design-tool`
- `gnss-positioning-simulator`

---

## Getting started

### Prerequisites

- Python 3.11 or newer
- Git
- A Python virtual environment
- JupyterLab or another Jupyter-compatible environment

### Clone the repository

```bash
git clone https://github.com/hunkarsuci/rf-space-systems-lab.git
cd rf-space-systems-lab
```

### Create a virtual environment

Linux and macOS:

```bash
python -m venv .venv
source .venv/bin/activate
```

Windows PowerShell:

```powershell
python -m venv .venv
.venv\Scripts\Activate.ps1
```

### Install the project

```bash
python -m pip install --upgrade pip
python -m pip install -e ".[dev]"
```

### Run tests

```bash
pytest
```

### Start JupyterLab

```bash
jupyter lab
```

---

## Engineering conventions

### Units

- Use SI units internally unless a model explicitly requires another convention.
- State units in variable names, docstrings, tables, and plots when ambiguity is possible.
- Convert user-facing units at system boundaries.
- Perform dimensional checks during derivations and reviews.

### Numerical work

- Document constants and their sources.
- State model assumptions.
- Check limiting cases.
- Compare results with hand calculations or published reference values.
- Use tolerances for floating-point tests.

### Code quality

- Use type hints for reusable functions.
- Write docstrings that describe equations, parameters, units, and return values.
- Keep notebooks readable and reproducible.
- Avoid copying reusable logic across notebooks.
- Add tests whenever code moves into `src/`.

---

## Git workflow

Use descriptive commits that identify the engineering contribution.

Good examples:

```text
Add frequency period and wavelength fundamentals
Implement and test decibel conversion functions
Add free-space path-loss parameter study
Implement pulsed-radar range equation
```

Avoid vague messages such as:

```text
update
changes
fix
```

Suggested phase tags:

```bash
git tag -a python-foundations-v1 -m "Complete engineering Python foundations"
git tag -a rf-foundations-v1 -m "Complete RF foundations phase"
git tag -a dsp-foundations-v1 -m "Complete DSP foundations phase"
```

See [CONTRIBUTING.md](CONTRIBUTING.md) for branch, commit, testing, and review conventions.

---

## Repository status

This repository is under active development. Immediate priorities are:

- Establish the expanded RF and space-systems identity
- Implement the first engineering-Python lesson
- Create the reusable package foundation
- Add initial unit tests
- Build the curriculum incrementally
- Preserve technical references and engineering assumptions

---

## Scope note

Radar is not inherently a space-system discipline. It is included because it shares the repository's RF, signal-processing, antenna, propagation, detection, and estimation foundations.

---

## License

A license has not yet been selected. Add a `LICENSE` file before distributing the project or accepting external contributions.