﻿/* 
	Data source (including pages & tables indicated below):
		MODTRAN Report 01/11/96: Knezys FX et al: The MODTRAN 2/3 Report and LOWTRAN 7 MODEL (in pdf)
*/
int const
	natm = 6,
	nmolec = 10,
	nz_mod = 50;
char
	molec_name[nmolec][4] = {"H2O", "CO2", "O3", "N2O", "CO", "CH4", "O2",  "NA", "NA", "NO2"},
	atmos_name[natm][64] = {"Tropical (15N Annual Average)", "Mid-Latitude Summer (45N July)",
                            "Mid-Latitude Winter (45N Jan)", "Sub-Arctic Summer (60N July)",
						    "Sub-Arctic Winter (60N Jan)",   "U. S. Standard (1976)"};
double
	zkm_mod[nz_mod] = {   0.0,  1.0,  2.0,  3.0,  4.0,   5.0,   6.0,   7.0,   8.0,   9.0,
	                     10.0, 11.0, 12.0, 13.0, 14.0,  15.0,  16.0,  17.0,  18.0,  19.0,
	                     20.0, 21.0, 22.0, 23.0, 24.0,  25.0,  27.5,  30.0,  32.5,  35.0,
	                     37.5, 40.0, 42.5, 45.0, 47.5,  50.0,  55.0,  60.0,  65.0,  70.0,
	                     75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0},
	Pmbar_mod[natm][nz_mod] = {/* pressure: mbar */ 
	                          1.013e+03, 9.040e+02, 8.050e+02, 7.150e+02, 6.330e+02, 5.590e+02, 4.920e+02, 4.320e+02, 3.780e+02, 3.290e+02, 2.860e+02, 2.470e+02, 2.130e+02, 1.820e+02, 1.560e+02, 1.320e+02, 1.110e+02, 9.370e+01, 7.890e+01, 6.660e+01, 6.650e+01, 4.800e+01, 4.090e+01, 3.500e+01, 3.000e+01, 2.570e+01, 1.763e+01, 1.220e+01, 8.520e+00, 6.000e+00, 4.260e+00, 3.050e+00, 2.200e+00, 1.590e+00, 1.160e+00, 8.540e-01, 4.560e-01, 2.390e-01, 1.210e-01, 5.800e-02, 2.600e-02, 1.100e-02, 4.400e-03, 1.720e-03, 6.880e-04, 2.890e-04, 1.300e-04, 6.470e-05, 3.600e-05, 2.250e-05,
                              1.013e+03, 9.020e+02, 8.020e+02, 7.100e+02, 6.280e+02, 5.540e+02, 4.870e+02, 4.260e+02, 3.720e+02, 3.240e+02, 2.810e+02, 2.430e+02, 2.090e+02, 1.790e+02, 1.530e+02, 1.300e+02, 1.110e+02, 9.500e+01, 8.120e+01, 6.950e+01, 5.950e+01, 5.100e+01, 4.370e+01, 3.760e+01, 3.220e+01, 2.770e+01, 1.907e+01, 1.320e+01, 9.300e+00, 6.520e+00, 4.640e+00, 3.330e+00, 2.410e+00, 1.760e+00, 1.290e+00, 9.510e-01, 5.150e-01, 2.720e-01, 1.390e-01, 6.700e-02, 3.000e-02, 1.200e-02, 4.480e-03, 1.640e-03, 6.250e-04, 2.580e-04, 1.170e-04, 6.110e-05, 3.560e-05, 2.270e-05,
                              1.018e+03, 8.973e+02, 7.897e+02, 6.938e+02, 6.081e+02, 5.313e+02, 4.627e+02, 4.016e+02, 3.473e+02, 2.993e+02, 2.568e+02, 2.199e+02, 1.882e+02, 1.611e+02, 1.378e+02, 1.178e+02, 1.007e+02, 8.610e+01, 7.360e+01, 6.280e+01, 5.370e+01, 4.580e+01, 3.910e+01, 3.340e+01, 2.860e+01, 2.440e+01, 1.646e+01, 1.110e+01, 7.560e+00, 5.180e+00, 3.600e+00, 2.530e+00, 1.800e+00, 1.290e+00, 9.400e-01, 6.830e-01, 3.620e-01, 1.880e-01, 9.500e-02, 4.700e-02, 2.220e-02, 1.030e-02, 4.560e-03, 1.980e-03, 8.770e-04, 4.074e-04, 2.000e-04, 1.057e-04, 5.980e-05, 3.600e-05,
                              1.010e+03, 8.960e+02, 7.929e+02, 7.000e+02, 6.160e+02, 5.410e+02, 4.740e+02, 4.130e+02, 3.590e+02, 3.108e+02, 2.677e+02, 2.300e+02, 1.977e+02, 1.700e+02, 1.460e+02, 1.260e+02, 1.080e+02, 9.280e+01, 7.980e+01, 6.860e+01, 5.900e+01, 5.070e+01, 4.360e+01, 3.750e+01, 3.228e+01, 2.780e+01, 1.923e+01, 1.340e+01, 9.400e+00, 6.610e+00, 4.720e+00, 3.400e+00, 2.480e+00, 1.820e+00, 1.340e+00, 9.870e-01, 5.370e-01, 2.880e-01, 1.470e-01, 7.100e-02, 3.200e-02, 1.250e-02, 4.510e-03, 1.610e-03, 6.060e-04, 2.480e-04, 1.130e-04, 6.000e-05, 3.540e-05, 2.260e-05,
                              1.013e+03, 8.878e+02, 7.775e+02, 6.798e+02, 5.932e+02, 5.158e+02, 4.467e+02, 3.853e+02, 3.308e+02, 2.829e+02, 2.418e+02, 2.067e+02, 1.766e+02, 1.510e+02, 1.291e+02, 1.103e+02, 9.431e+01, 8.058e+01, 6.882e+01, 5.875e+01, 5.014e+01, 4.277e+01, 3.647e+01, 3.109e+01, 2.649e+01, 2.256e+01, 1.513e+01, 1.020e+01, 6.910e+00, 4.701e+00, 3.230e+00, 2.243e+00, 1.570e+00, 1.113e+00, 7.900e-01, 5.719e-01, 2.990e-01, 1.550e-01, 7.900e-02, 4.000e-02, 2.000e-02, 9.660e-03, 4.500e-03, 2.022e-03, 9.070e-04, 4.230e-04, 2.070e-04, 1.080e-04, 6.000e-05, 3.590e-05,
                              1.013e+03, 8.988e+02, 7.950e+02, 7.012e+02, 6.166e+02, 5.405e+02, 4.722e+02, 4.111e+02, 3.565e+02, 3.080e+02, 2.650e+02, 2.270e+02, 1.940e+02, 1.658e+02, 1.417e+02, 1.211e+02, 1.035e+02, 8.850e+01, 7.565e+01, 6.467e+01, 5.529e+01, 4.729e+01, 4.047e+01, 3.467e+01, 2.972e+01, 2.549e+01, 1.743e+01, 1.197e+01, 8.010e+00, 5.746e+00, 4.150e+00, 2.871e+00, 2.060e+00, 1.491e+00, 1.090e+00, 7.978e-01, 4.250e-01, 2.190e-01, 1.090e-01, 5.220e-02, 2.400e-02, 1.050e-02, 4.460e-03, 1.840e-03, 7.600e-04, 3.200e-04, 1.450e-04, 7.100e-05, 4.010e-05, 2.540e-05},
	Tkelv_mod[natm][nz_mod] = {/* temperature: K */
	                          299.7, 293.7, 287.7, 283.7, 277.0, 270.3, 263.6, 257.0, 250.3, 243.6, 237.0, 230.1, 223.6, 217.0, 210.3, 203.7, 197.0, 194.8, 198.8, 202.7, 206.7, 210.7, 214.6, 217.0, 219.2, 221.4, 227.0, 232.3, 237.7, 243.1, 248.5, 254.0, 259.4, 264.8, 269.6, 270.2, 263.4, 253.1, 236.0, 218.9, 201.8, 184.8, 177.1, 177.0, 184.3, 190.7, 212.0, 241.6, 299.7, 380.0,
                              294.2, 289.7, 285.2, 279.2, 273.2, 267.2, 261.2, 254.7, 248.2, 241.7, 235.3, 228.8, 222.3, 215.8, 215.7, 215.7, 215.7, 215.7, 216.8, 217.9, 219.2, 220.4, 221.6, 222.8, 223.9, 225.1, 228.5, 233.7, 239.0, 245.2, 251.3, 257.5, 263.7, 269.9, 275.2, 275.7, 269.3, 257.1, 240.1, 218.1, 196.1, 174.1, 165.1, 165.0, 178.3, 190.5, 222.2, 262.4, 316.8, 380.0,
                              272.2, 268.7, 265.2, 261.7, 255.7, 249.7, 243.7, 237.7, 231.7, 225.7, 219.7, 219.2, 218.7, 218.2, 217.7, 217.2, 216.7, 216.2, 215.7, 215.2, 215.2, 215.2, 215.2, 215.2, 215.2, 215.2, 215.5, 217.4, 220.4, 227.9, 235.5, 243.2, 250.8, 258.5, 265.1, 265.7, 260.6, 250.8, 240.9, 230.7, 220.4, 210.1, 199.8, 199.5, 208.3, 218.6, 237.1, 259.5, 293.0, 333.0,
                              287.2, 281.7, 276.3, 270.9, 265.5, 260.1, 253.1, 246.1, 239.2, 232.2, 225.2, 225.2, 225.2, 225.2, 225.2, 225.2, 225.2, 225.2, 225.2, 225.2, 225.2, 225.2, 225.2, 225.2, 226.6, 228.1, 231.0, 235.1, 240.0, 247.2, 254.6, 262.1, 269.5, 273.6, 276.2, 277.2, 274.0, 262.7, 239.7, 216.6, 193.6, 170.6, 161.7, 161.6, 176.8, 190.4, 226.0, 270.1, 322.7, 380.0,
                              257.2, 259.1, 255.9, 252.7, 247.7, 240.9, 234.1, 227.3, 220.6, 217.2, 217.2, 217.2, 217.2, 217.2, 217.2, 217.2, 216.6, 216.0, 215.4, 214.8, 214.2, 213.6, 213.0, 212.4, 211.8, 211.2, 213.6, 216.0, 218.5, 222.3, 228.5, 234.7, 240.8, 247.0, 253.2, 259.3, 259.1, 250.9, 248.4, 245.4, 234.7, 223.9, 213.1, 202.3, 211.0, 218.5, 234.0, 252.6, 288.5, 333.0,
                              288.2, 281.7, 275.2, 268.7, 262.2, 255.7, 249.2, 242.7, 236.2, 229.7, 223.3, 216.8, 216.7, 216.7, 216.7, 216.7, 216.7, 216.7, 216.7, 216.7, 216.7, 217.6, 218.6, 219.6, 220.6, 221.6, 224.0, 226.5, 230.0, 236.5, 242.9, 250.4, 257.3, 264.2, 270.6, 270.7, 260.8, 247.0, 233.3, 219.6, 208.4, 198.6, 188.9, 186.9, 188.4, 195.1, 208.8, 240.0, 300.0, 360.0
                              },
	Dcm3_mod[natm][nz_mod] = {/* volumetric number concentrtaion (density in MODTRAN): molecules/cm3 = cm-3 */
	                           2.450e+19, 2.231e+19, 2.028e+19, 1.827e+19, 1.656e+19, 1.499e+19, 1.353e+19, 1.218e+19, 1.095e+19, 9.789e+18, 8.747e+18, 7.780e+18, 6.904e+18, 6.079e+18, 5.377e+18, 4.697e+18, 4.084e+18, 3.486e+18, 2.877e+18, 2.381e+18, 1.981e+18, 1.651e+18, 1.381e+18, 1.169e+18, 9.920e+17, 8.413e+17, 5.629e+17, 3.807e+17, 2.598e+17, 1.789e+17, 1.243e+17, 8.703e+16, 6.147e+16, 4.352e+16, 3.119e+16, 2.291e+16, 1.255e+16, 6.844e+15, 3.716e+15, 1.920e+15, 9.338e+14, 4.314e+14, 1.801e+14, 7.043e+13, 2.706e+13, 1.098e+13, 4.445e+12, 1.941e+12, 8.706e+11, 4.225e+11,
                               2.496e+19, 2.257e+19, 2.038e+19, 1.843e+19, 1.666e+19, 1.503e+19, 1.351e+19, 1.212e+19, 1.086e+19, 9.716e+18, 8.656e+18, 7.698e+18, 6.814e+18, 6.012e+18, 5.141e+18, 4.368e+18, 3.730e+18, 3.192e+18, 2.715e+18, 2.312e+18, 1.967e+18, 1.677e+18, 1.429e+18, 1.223e+18, 1.042e+18, 8.919e+17, 6.050e+17, 4.094e+17, 2.820e+17, 1.927e+17, 1.338e+17, 9.373e+16, 6.624e+16, 4.726e+16, 3.398e+16, 2.500e+16, 1.386e+16, 7.668e+15, 4.196e+15, 2.227e+15, 1.109e+15, 4.996e+14, 1.967e+14, 7.204e+13, 2.541e+13, 9.816e+12, 3.816e+12, 1.688e+12, 8.145e+11, 4.330e+11,
                               2.711e+19, 2.420e+19, 2.158e+19, 1.922e+19, 1.724e+19, 1.542e+19, 1.376e+19, 1.225e+19, 1.086e+19, 9.612e+18, 8.472e+18, 7.271e+18, 6.237e+18, 5.351e+18, 4.588e+18, 3.931e+18, 3.368e+18, 2.886e+18, 2.473e+18, 2.115e+18, 1.809e+18, 1.543e+18, 1.317e+18, 1.125e+18, 9.633e+17, 8.218e+17, 5.536e+17, 3.701e+17, 2.486e+17, 1.647e+17, 1.108e+17, 7.540e+16, 5.202e+16, 3.617e+16, 2.570e+16, 1.863e+16, 1.007e+16, 5.433e+15, 2.858e+15, 1.477e+15, 7.301e+14, 3.553e+14, 1.654e+14, 7.194e+13, 3.052e+13, 1.351e+13, 6.114e+12, 2.952e+12, 1.479e+12, 7.836e+11,
                               2.549e+19, 2.305e+19, 2.080e+19, 1.873e+19, 1.682e+19, 1.508e+19, 1.357e+19, 1.216e+19, 1.088e+19, 9.701e+18, 8.616e+18, 7.402e+18, 6.363e+18, 5.471e+18, 4.699e+18, 4.055e+18, 3.476e+18, 2.987e+18, 2.568e+18, 2.208e+18, 1.899e+18, 1.632e+18, 1.403e+18, 1.207e+18, 1.033e+18, 8.834e+17, 6.034e+17, 4.131e+17, 2.839e+17, 1.938e+17, 1.344e+17, 9.402e+16, 6.670e+16, 4.821e+16, 3.516e+16, 2.581e+16, 1.421e+16, 7.946e+15, 4.445e+15, 2.376e+15, 1.198e+15, 5.311e+14, 2.022e+14, 7.221e+13, 2.484e+13, 9.441e+12, 3.624e+12, 1.610e+12, 7.951e+11, 4.311e+11,
                               2.855e+19, 2.484e+19, 2.202e+19, 1.950e+19, 1.736e+19, 1.552e+19, 1.383e+19, 1.229e+19, 1.087e+19, 9.440e+18, 8.069e+18, 6.898e+18, 5.893e+18, 5.039e+18, 4.308e+18, 3.681e+18, 3.156e+18, 2.104e+18, 2.316e+18, 1.982e+18, 1.697e+18, 1.451e+18, 1.241e+18, 1.061e+18, 9.065e+17, 7.742e+17, 5.134e+17, 3.423e+17, 2.292e+17, 1.533e+17, 1.025e+17, 6.927e+16, 4.726e+16, 3.266e+16, 2.261e+16, 1.599e+16, 8.364e+15, 4.478e+15, 2.305e+15, 1.181e+15, 6.176e+14, 3.127e+14, 1.531e+14, 7.244e+13, 3.116e+13, 1.403e+13, 6.412e+12, 3.099e+12, 1.507e+12, 7.814e+11,
                               2.548e+19, 2.313e+19, 2.094e+19, 1.891e+19, 1.704e+19, 1.532e+19, 1.373e+19, 1.228e+19, 1.094e+19, 9.719e+18, 8.602e+18, 7.589e+18, 6.489e+18, 5.546e+18, 4.739e+18, 4.050e+18, 3.462e+18, 2.960e+18, 2.530e+18, 2.163e+18, 1.849e+18, 1.575e+18, 1.342e+18, 1.144e+18, 9.765e+17, 8.337e+17, 5.640e+17, 3.830e+17, 2.524e+17, 1.761e+17, 1.238e+17, 8.310e+16, 5.803e+16, 4.090e+16, 2.920e+16, 2.136e+16, 1.181e+16, 6.426e+15, 3.386e+15, 1.723e+15, 8.347e+14, 3.832e+14, 1.711e+14, 7.136e+13, 2.924e+13, 1.189e+13, 5.033e+12, 2.144e+12, 9.688e+11, 5.114e+11},
	H2O_ppmv[natm][nz_mod] = {/* ppmv for the HITRAN molecule #1 (water vapour): p.25, Sec.2.2.2, Table 1 (a-f) */
	                          2.59e+04, 1.95e+04, 1.53e+04, 8.60e+03, 4.44e+03, 3.35e+03, 2.10e+03, 1.29e+03, 7.64e+02, 4.10e+02, 1.91e+02, 7.31e+01, 2.91e+01, 9.90e+00, 6.22e+00, 4.00e+00, 3.00e+00, 2.90e+00, 2.75e+00, 2.60e+00, 2.60e+00, 2.65e+00, 2.80e+00, 2.90e+00, 3.20e+00, 3.25e+00, 3.60e+00, 4.00e+00, 4.30e+00, 4.60e+00, 4.90e+00, 5.20e+00, 5.50e+00, 5.70e+00, 5.90e+00, 6.00e+00, 6.00e+00, 6.00e+00, 5.40e+00, 4.50e+00, 3.30e+00, 2.10e+00, 1.30e+00, 8.50e-01, 5.40e-01, 4.00e-01, 3.40e-01, 1.80e-01, 2.40e-01, 2.00e-01,
                              1.88e+04, 1.38e+04, 9.68e+03, 5.98e+03, 3.81e+03, 2.23e+03, 1.51e+03, 1.02e+03, 6.46e+02, 4.13e+02, 2.47e+02, 9.56e+01, 2.94e+01, 8.00e+00, 5.00e+00, 3.40e+00, 3.30e+00, 3.20e+00, 3.15e+00, 3.20e+00, 3.30e+00, 3.45e+00, 3.60e+00, 3.85e+00, 4.00e+00, 4.20e+00, 4.45e+00, 4.70e+00, 4.85e+00, 4.95e+00, 5.00e+00, 5.10e+00, 5.30e+00, 5.45e+00, 5.50e+00, 5.50e+00, 5.35e+00, 5.00e+00, 4.40e+00, 3.70e+00, 2.95e+00, 2.10e+00, 1.33e+00, 8.50e-01, 5.40e-01, 4.00e-01, 3.40e-01, 2.80e-01, 2.40e-01, 2.00e-01,
                              4.32e+03, 3.45e+03, 2.79e+03, 2.09e+03, 1.28e+03, 8.24e+02, 5.10e+02, 2.32e+02, 1.08e+02, 5.57e+01, 2.96e+01, 1.00e+01, 6.00e+00, 5.00e+00, 4.80e+00, 4.70e+00, 4.60e+00, 4.50e+00, 4.50e+00, 4.50e+00, 4.50e+00, 4.50e+00, 4.53e+00, 4.55e+00, 4.60e+00, 4.65e+00, 4.70e+00, 4.75e+00, 4.80e+00, 4.85e+00, 4.90e+00, 4.95e+00, 5.00e+00, 5.00e+00, 5.00e+00, 4.95e+00, 4.85e+00, 4.50e+00, 4.00e+00, 3.30e+00, 2.70e+00, 2.00e+00, 1.33e+00, 8.50e-01, 5.40e-01, 4.00e-01, 3.40e-01, 2.80e-01, 2.40e-01, 2.00e-01,
                              1.19e+04, 8.70e+03, 6.75e+03, 4.82e+03, 3.38e+03, 2.22e+03, 1.33e+03, 7.97e+02, 4.00e+02, 1.30e+02, 4.24e+01, 1.33e+01, 6.00e+00, 4.45e+00, 4.00e+00, 4.00e+00, 4.00e+00, 4.05e+00, 4.30e+00, 4.50e+00, 4.60e+00, 4.70e+00, 4.80e+00, 4.83e+00, 4.85e+00, 4.90e+00, 4.95e+00, 5.00e+00, 5.00e+00, 5.00e+00, 5.00e+00, 5.00e+00, 5.00e+00, 5.00e+00, 5.00e+00, 4.95e+00, 4.85e+00, 4.50e+00, 4.00e+00, 3.30e+00, 2.70e+00, 2.00e+00, 1.33e+00, 8.50e-01, 5.40e-01, 4.00e-01, 3.40e-01, 2.80e-01, 2.40e-01, 2.00e-01,
                              1.41e+03, 1.62e+03, 1.43e+03, 1.17e+03, 7.90e+02, 4.31e+02, 2.37e+02, 1.47e+02, 3.38e+01, 2.98e+01, 2.00e+01, 1.00e+01, 6.00e+00, 4.45e+00, 4.50e+00, 4.55e+00, 4.60e+00, 4.65e+00, 4.70e+00, 4.75e+00, 4.80e+00, 4.85e+00, 4.90e+00, 4.95e+00, 5.00e+00, 5.00e+00, 5.00e+00, 5.00e+00, 5.00e+00, 5.00e+00, 5.00e+00, 5.00e+00, 5.00e+00, 5.00e+00, 5.00e+00, 4.95e+00, 4.85e+00, 4.50e+00, 4.00e+00, 3.30e+00, 2.70e+00, 2.00e+00, 1.33e+00, 8.50e-01, 5.40e-01, 4.00e-01, 3.40e-01, 2.80e-01, 2.40e-01, 2.00e-01,
                              7.75e+03, 6.07e+03, 4.63e+03, 3.18e+03, 2.16e+03, 1.40e+03, 9.25e+02, 5.72e+02, 3.67e+02, 1.58e+02, 7.00e+01, 3.61e+01, 1.91e+01, 1.09e+01, 5.93e+00, 5.00e+00, 3.95e+00, 3.85e+00, 3.83e+00, 3.85e+00, 3.90e+00, 3.98e+00, 4.07e+00, 4.20e+00, 4.30e+00, 4.43e+00, 4.58e+00, 4.73e+00, 4.83e+00, 4.90e+00, 4.95e+00, 5.03e+00, 5.15e+00, 5.23e+00, 5.25e+00, 5.23e+00, 5.10e+00, 4.75e+00, 4.20e+00, 3.50e+00, 2.83e+00, 2.05e+00, 1.33e+00, 8.50e-01, 5.40e-01, 4.00e-01, 3.40e-01, 2.80e-01, 2.40e-01, 2.00e-01},
	CO2_ppmv[nz_mod] = {/* ppmv for the HITRAN molecule #2 (carbon dioxide), sezonaly invariant: p.25, Sec.2.2.2, Table 2*/
	                    3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.30e+02, 3.28e+02, 3.20e+02, 3.10e+02, 2.70e+02, 1.95e+02, 1.10e+02, 6.00e+01, 4.00e+01, 3.50e+01},
	O3_ppmv[natm][nz_mod] = {/* ppmv for the HITRAN molecule #3 (ozone): p.25, Sec.2.2.2, Table 1 (a-f)*/
	                         2.87e-02, 3.15e-02, 3.34e-02, 3.50e-02, 3.56e-02, 3.77e-02, 3.99e-02, 4.22e-02, 4.47e-02, 5.00e-02, 5.60e-02, 6.61e-02, 7.82e-02, 9.29e-02, 1.05e-01, 1.26e-01, 1.44e-01, 2.50e-01, 5.00e-01, 9.50e-01, 1.40e+00, 1.80e+00, 2.40e+00, 3.40e+00, 4.30e+00, 5.40e+00, 7.80e+00, 9.30e+00, 9.85e+00, 9.70e+00, 8.80e+00, 7.50e+00, 5.90e+00, 4.50e+00, 3.45e+00, 2.80e+00, 1.80e+00, 1.10e+00, 6.50e-01, 3.00e-01, 1.80e-01, 3.30e-01, 5.00e-01, 5.20e-01, 5.00e-01, 4.00e-01, 2.00e-01, 5.00e-02, 5.00e-03, 5.00e-04,
                             3.02e-02, 3.34e-02, 3.69e-02, 4.22e-02, 4.82e-02, 5.51e-02, 6.41e-02, 7.76e-02, 9.13e-02, 1.11e-01, 1.30e-01, 1.79e-01, 2.23e-01, 3.00e-01, 4.40e-01, 5.00e-01, 6.00e-01, 7.00e-01, 1.00e+00, 1.50e+00, 2.00e+00, 2.40e+00, 2.90e+00, 3.40e+00, 4.00e+00, 4.30e+00, 6.00e+00, 7.00e+00, 8.10e+00, 8.90e+00, 8.70e+00, 7.55e+00, 5.90e+00, 4.50e+00, 3.50e+00, 2.80e+00, 1.80e+00, 1.30e+00, 8.00e-01, 4.00e-01, 1.90e-01, 2.00e-01, 5.70e-01, 7.50e-01, 7.00e-01, 4.00e-01, 2.00e-01, 5.00e-02, 5.00e-03, 5.00e-04,
                             2.78e-02, 2.80e-02, 2.85e-02, 3.20e-02, 3.57e-02, 4.72e-02, 5.84e-02, 7.89e-02, 1.04e-01, 1.57e-01, 2.37e-01, 3.62e-01, 5.23e-01, 7.04e-01, 8.00e-01, 9.00e-01, 1.10e+00, 1.40e+00, 1.80e+00, 2.30e+00, 2.90e+00, 3.50e+00, 3.90e+00, 4.30e+00, 4.70e+00, 5.10e+00, 5.60e+00, 6.10e+00, 6.80e+00, 7.10e+00, 7.20e+00, 6.90e+00, 5.90e+00, 4.60e+00, 3.70e+00, 2.75e+00, 1.70e+00, 1.00e+00, 5.50e-01, 3.20e-01, 2.50e-01, 2.30e-01, 5.50e-01, 8.00e-01, 8.00e-01, 4.00e-01, 2.00e-01, 5.00e-02, 5.00e-03, 5.00e-04,
                             2.41e-02, 2.94e-02, 3.38e-02, 3.89e-02, 4.48e-02, 5.33e-02, 6.56e-02, 7.74e-02, 9.11e-02, 1.42e-01, 1.89e-01, 3.05e-01, 4.10e-01, 5.00e-01, 6.00e-01, 7.00e-01, 8.50e-01, 1.00e+00, 1.30e+00, 1.70e+00, 2.10e+00, 2.70e+00, 3.30e+00, 3.70e+00, 4.20e+00, 4.50e+00, 5.30e+00, 5.70e+00, 6.90e+00, 7.70e+00, 7.80e+00, 7.00e+00, 5.40e+00, 4.20e+00, 3.20e+00, 2.50e+00, 1.70e+00, 1.20e+00, 8.00e-01, 4.00e-01, 2.00e-01, 1.80e-01, 6.50e-01, 9.00e-01, 8.00e-01, 4.00e-01, 2.00e-01, 5.00e-02, 5.00e-03, 5.00e-04,
                             1.80e-02, 2.07e-02, 2.34e-02, 2.77e-02, 3.25e-02, 3.80e-02, 4.45e-02, 7.25e-02, 1.04e-01, 2.10e-01, 3.00e-01, 3.50e-01, 4.00e-01, 6.50e-01, 9.00e-01, 1.20e+00, 1.50e+00, 1.90e+00, 2.45e+00, 3.10e+00, 3.70e+00, 4.00e+00, 4.20e+00, 4.50e+00, 4.60e+00, 4.70e+00, 4.90e+00, 5.40e+00, 5.90e+00, 6.20e+00, 6.25e+00, 5.90e+00, 5.10e+00, 4.10e+00, 3.00e+00, 2.60e+00, 1.60e+00, 9.50e-01, 6.50e-01, 5.00e-01, 3.30e-01, 1.30e-01, 7.50e-01, 8.00e-01, 8.00e-01, 4.00e-01, 2.00e-01, 5.00e-02, 5.00e-03, 5.00e-04,
                             2.66e-02, 2.93e-02, 3.24e-02, 3.32e-02, 3.39e-02, 3.77e-02, 4.11e-02, 5.01e-02, 5.97e-02, 9.17e-02, 1.31e-01, 2.15e-01, 3.10e-01, 3.85e-01, 5.03e-01, 6.51e-01, 8.70e-01, 1.19e+00, 1.59e+00, 2.03e+00, 2.58e+00, 3.03e+00, 3.65e+00, 4.17e+00, 4.63e+00, 5.12e+00, 5.80e+00, 6.55e+00, 7.37e+00, 7.84e+00, 7.80e+00, 7.30e+00, 6.20e+00, 5.25e+00, 4.10e+00, 3.10e+00, 1.80e+00, 1.10e+00, 7.00e-01, 3.00e-01, 2.50e-01, 3.00e-01, 5.00e-01, 7.00e-01, 7.00e-01, 4.00e-01, 2.00e-01, 5.00e-02, 5.00e-03, 5.00e-04},
	N2O_ppmv[natm][nz_mod] = {/* ppmv for the HITRAN molecule #4 (nitrogen oxide): p.25, Sec.2.2.2, Table 1 (a-f)*/
	                          3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.18e-01, 3.14e-01, 3.10e-01, 3.05e-01, 3.00e-01, 2.94e-01, 2.88e-01, 2.78e-01, 2.67e-01, 2.53e-01, 2.37e-01, 2.19e-01, 2.05e-01, 1.97e-01, 1.88e-01, 1.76e-01, 1.59e-01, 1.42e-01, 1.17e-01, 9.28e-02, 6.69e-02, 4.51e-02, 2.75e-02, 1.59e-02, 9.38e-03, 4.75e-03, 3.00e-03, 2.07e-03, 1.51e-03, 1.15e-03, 8.89e-04, 7.06e-04, 5.72e-04, 4.71e-04, 3.93e-04, 3.32e-04, 2.84e-04, 2.44e-04, 2.12e-04, 1.85e-04,
                              3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.16e-01, 3.10e-01, 2.99e-01, 2.94e-01, 2.86e-01, 2.80e-01, 2.72e-01, 2.61e-01, 2.42e-01, 2.17e-01, 1.84e-01, 1.61e-01, 1.32e-01, 1.15e-01, 1.04e-01, 9.62e-02, 8.96e-02, 8.01e-02, 6.70e-02, 4.96e-02, 3.70e-02, 2.52e-02, 1.74e-02, 1.16e-02, 7.67e-03, 5.32e-03, 3.22e-03, 2.03e-03, 1.40e-03, 1.02e-03, 7.77e-04, 6.26e-04, 5.17e-04, 4.35e-04, 3.73e-04, 3.24e-04, 2.84e-04, 2.52e-04, 2.26e-04, 2.04e-04, 1.85e-04,
                              3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.16e-01, 3.10e-01, 2.99e-01, 2.94e-01, 2.86e-01, 2.80e-01, 2.72e-01, 2.61e-01, 2.42e-01, 2.17e-01, 1.84e-01, 1.62e-01, 1.36e-01, 1.23e-01, 1.12e-01, 1.05e-01, 9.66e-02, 8.69e-02, 7.52e-02, 6.13e-02, 5.12e-02, 3.97e-02, 3.00e-02, 2.08e-02, 1.31e-02, 8.07e-03, 4.16e-03, 2.63e-03, 1.81e-03, 1.32e-03, 1.01e-03, 7.88e-04, 6.33e-04, 5.19e-04, 4.33e-04, 3.67e-04, 3.14e-04, 2.72e-04, 2.37e-04, 2.09e-04, 1.85e-04,
                              3.10e-01, 3.10e-01, 3.10e-01, 3.10e-01, 3.08e-01, 3.02e-01, 2.91e-01, 2.82e-01, 2.76e-01, 2.70e-01, 2.65e-01, 2.60e-01, 2.55e-01, 2.49e-01, 2.43e-01, 2.36e-01, 2.28e-01, 2.18e-01, 2.04e-01, 1.82e-01, 1.57e-01, 1.35e-01, 1.22e-01, 1.10e-01, 9.89e-02, 8.78e-02, 7.33e-02, 5.94e-02, 4.15e-02, 3.03e-02, 1.95e-02, 1.27e-02, 9.00e-03, 6.29e-03, 4.56e-03, 2.80e-03, 1.77e-03, 1.21e-03, 8.87e-04, 6.76e-04, 5.54e-04, 4.65e-04, 3.98e-04, 3.46e-04, 3.05e-04, 2.71e-04, 2.44e-04, 2.21e-04, 2.02e-04, 1.85e-04,
                              3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.16e-01, 3.10e-01, 2.99e-01, 2.94e-01, 2.86e-01, 2.80e-01, 2.72e-01, 2.61e-01, 2.42e-01, 2.17e-01, 1.84e-01, 1.62e-01, 1.36e-01, 1.23e-01, 1.12e-01, 1.04e-01, 9.57e-02, 8.60e-02, 7.31e-02, 5.71e-02, 4.67e-02, 3.44e-02, 2.47e-02, 1.63e-02, 1.07e-02, 7.06e-03, 3.97e-03, 2.51e-03, 1.73e-03, 1.26e-03, 9.60e-04, 7.55e-04, 6.10e-04, 5.02e-04, 4.21e-04, 3.58e-04, 3.08e-04, 2.68e-04, 2.35e-04, 2.08e-04, 1.85e-04,
                              3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.20e-01, 3.18e-01, 3.14e-01, 3.10e-01, 3.05e-01, 3.00e-01, 2.94e-01, 2.88e-01, 2.78e-01, 2.67e-01, 2.53e-01, 2.37e-01, 2.19e-01, 2.05e-01, 1.97e-01, 1.88e-01, 1.76e-01, 1.59e-01, 1.42e-01, 1.17e-01, 9.28e-02, 6.69e-02, 4.51e-02, 2.75e-02, 1.59e-02, 9.38e-03, 4.75e-03, 3.00e-03, 2.07e-03, 1.51e-03, 1.15e-03, 8.89e-04, 7.06e-04, 5.72e-04, 4.71e-04, 3.93e-04, 3.32e-04, 2.84e-04, 2.44e-04, 2.12e-04, 1.85e-04},
	CO_ppmv[natm][nz_mod] = {/* ppmv for the HITRAN molecule #5 (carbon monoxide): p.25, Sec.2.2.2, Table 1 (a-f)*/
	                         1.50e-01, 1.45e-01, 1.40e-01, 1.35e-01, 1.31e-01, 1.30e-01, 1.29e-01, 1.25e-01, 1.19e-01, 1.09e-01, 9.96e-02, 9.96e-02, 7.81e-02, 6.37e-02, 5.03e-02, 3.94e-02, 3.07e-02, 2.49e-02, 1.97e-02, 1.55e-02, 1.33e-02, 1.23e-02, 1.23e-02, 1.31e-02, 1.40e-02, 1.52e-02, 1.72e-02, 2.00e-02, 2.27e-02, 2.49e-02, 2.74e-02, 3.10e-02, 3.51e-02, 3.99e-02, 4.48e-02, 5.09e-02, 5.99e-02, 6.96e-02, 9.19e-02, 1.94e-01, 5.69e-01, 1.55e+00, 3.85e+01, 6.59e+00, 1.04e+01, 1.71e+01, 2.47e+01, 3.36e+01, 4.15e+01, 5.00e+01,
                             1.50e-01, 1.45e-01, 1.40e-01, 1.35e-01, 1.31e-01, 1.30e-01, 1.29e-01, 1.25e-01, 1.19e-01, 1.09e-01, 9.96e-02, 8.96e-02, 7.81e-02, 6.37e-02, 5.03e-02, 3.94e-02, 3.07e-02, 2.49e-02, 1.97e-02, 1.55e-02, 1.33e-02, 1.23e-02, 1.23e-02, 1.31e-02, 1.40e-02, 1.52e-02, 1.72e-02, 2.00e-02, 2.27e-02, 2.49e-02, 2.72e-02, 2.96e-02, 3.14e-02, 3.31e-02, 3.49e-02, 3.65e-02, 3.92e-02, 4.67e-02, 6.40e-02, 1.18e-01, 2.94e-01, 6.82e-01, 1.47e+00, 2.85e+00, 5.17e+00, 1.01e+01, 1.87e+01, 2.86e+01, 3.89e+01, 5.00e+01,
                             1.50e-01, 1.45e-01, 1.40e-01, 1.35e-01, 1.31e-01, 1.30e-01, 1.29e-01, 1.25e-01, 1.19e-01, 1.09e-01, 9.96e-02, 8.96e-02, 7.81e-02, 6.37e-02, 5.03e-02, 3.94e-02, 3.07e-02, 2.42e-02, 1.97e-02, 1.55e-02, 1.33e-02, 1.23e-02, 1.23e-02, 1.31e-02, 1.40e-02, 1.50e-02, 1.60e-02, 1.71e-02, 1.85e-02, 2.00e-02, 2.15e-02, 2.33e-02, 2.62e-02, 3.06e-02, 3.80e-02, 6.25e-02, 1.48e-01, 2.93e-01, 5.59e-01, 1.08e+00, 1.90e+00, 2.96e+00, 4.53e+00, 6.86e+00, 1.05e+01, 1.71e+01, 2.47e+01, 3.36e+01, 4.15e+01, 5.00e+01,
                             1.50e-01, 1.45e-01, 1.40e-01, 1.35e-01, 1.31e-01, 1.30e-01, 1.29e-01, 1.25e-01, 1.19e-01, 1.09e-01, 9.96e-02, 8.96e-02, 7.81e-02, 6.37e-02, 5.03e-02, 3.94e-02, 3.07e-02, 2.49e-02, 1.97e-02, 1.55e-02, 1.33e-02, 1.23e-02, 1.23e-02, 1.31e-02, 1.40e-02, 1.51e-02, 1.65e-02, 1.81e-02, 2.00e-02, 2.18e-02, 2.34e-02, 2.50e-02, 2.65e-02, 2.81e-02, 3.00e-02, 3.22e-02, 3.65e-02, 4.59e-02, 6.38e-02, 1.18e-01, 3.03e-01, 7.89e-01, 1.82e+00, 3.40e+00, 5.92e+00, 1.04e+01, 1.88e+01, 2.87e+01, 3.89e+01, 5.00e+01,
                             1.50e-01, 1.45e-01, 1.40e-01, 1.35e-01, 1.31e-01, 1.30e-01, 1.29e-01, 1.25e-01, 1.19e-01, 1.09e-01, 9.96e-02, 8.96e-02, 7.81e-02, 6.37e-02, 5.03e-02, 3.94e-02, 3.07e-02, 2.49e-02, 1.97e-02, 1.55e-02, 1.33e-02, 1.23e-02, 1.23e-02, 1.31e-02, 1.40e-02, 1.52e-02, 1.72e-02, 2.04e-02, 2.49e-02, 3.17e-02, 4.43e-02, 6.47e-02, 1.04e-01, 1.51e-01, 2.16e-01, 3.14e-01, 4.84e-01, 7.15e-01, 1.07e+00, 1.52e+00, 2.17e+00, 3.06e+00, 4.56e+00, 6.88e+00, 1.06e+01, 1.71e+01, 2.47e+01, 3.36e+01, 4.15e+01, 5.00e+01,
                             1.50e-01, 1.45e-01, 1.40e-01, 1.35e-01, 1.31e-01, 1.30e-01, 1.29e-01, 1.25e-01, 1.19e-01, 1.09e-01, 9.96e-02, 8.96e-02, 7.81e-02, 6.37e-02, 5.03e-02, 3.94e-02, 3.07e-02, 2.49e-02, 1.97e-02, 1.55e-02, 1.33e-02, 1.23e-02, 1.23e-02, 1.31e-02, 1.40e-02, 1.50e-02, 1.60e-02, 1.71e-02, 1.85e-02, 2.01e-02, 2.22e-02, 2.50e-02, 2.82e-02, 3.24e-02, 3.72e-02, 4.60e-02, 6.64e-02, 1.07e-01, 1.86e-01, 3.06e-01, 6.38e-01, 1.50e+00, 3.24e+00, 5.84e+00, 1.01e+01, 1.69e+01, 2.47e+01, 3.36e+01, 4.15e+01, 5.00e+01},
	CH4_ppmv[natm][nz_mod] = {/* ppmv for the HITRAN molecule #6 (methane): p.25, Sec.2.2.2, Table 1 (a-f)*/
	                          1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.69e+00, 1.69e+00, 1.68e+00, 1.66e+00, 1.65e+00, 1.63e+00, 1.61e+00, 1.58e+00, 1.55e+00, 1.52e+00, 1.48e+00, 1.42e+00, 1.36e+00, 1.27e+00, 1.19e+00, 1.12e+00, 1.06e+00, 9.87e-01, 9.14e-01, 8.30e-01, 7.46e-01, 6.62e-01, 5.64e-01, 4.61e-01, 3.63e-01, 2.77e-01, 2.10e-01, 1.65e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.40e-01, 1.30e-01, 1.20e-01, 1.10e-01, 9.50e-02, 6.00e-02, 3.00e-02,
                              1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.69e+00, 1.67e+00, 1.65e+00, 1.63e+00, 1.62e+00, 1.58e+00, 1.54e+00, 1.51e+00, 1.48e+00, 1.45e+00, 1.42e+00, 1.39e+00, 1.36e+00, 1.32e+00, 1.28e+00, 1.22e+00, 1.15e+00, 1.07e+00, 9.73e-01, 8.80e-01, 7.89e-01, 7.05e-01, 6.32e-01, 5.59e-01, 5.01e-01, 4.45e-01, 3.92e-01, 3.39e-01, 2.87e-01, 2.38e-01, 1.94e-01, 1.57e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.40e-01, 1.30e-01, 1.20e-01, 1.10e-01, 9.50e-02, 6.00e-02, 3.00e-02,
                              1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.69e+00, 1.67e+00, 1.65e+00, 1.63e+00, 1.62e+00, 1.58e+00, 1.54e+00, 1.51e+00, 1.48e+00, 1.45e+00, 1.42e+00, 1.39e+00, 1.36e+00, 1.32e+00, 1.28e+00, 1.22e+00, 1.15e+00, 1.07e+00, 9.73e-01, 8.80e-01, 7.93e-01, 7.13e-01, 6.44e-01, 5.75e-01, 5.05e-01, 4.48e-01, 3.93e-01, 3.40e-01, 2.88e-01, 2.39e-01, 1.94e-01, 1.57e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.40e-01, 1.30e-01, 1.20e-01, 1.10e-01, 9.50e-02, 6.00e-02, 3.00e-02,
                              1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.69e+00, 1.67e+00, 1.65e+00, 1.63e+00, 1.62e+00, 1.58e+00, 1.54e+00, 1.51e+00, 1.47e+00, 1.43e+00, 1.39e+00, 1.34e+00, 1.29e+00, 1.23e+00, 1.16e+00, 1.07e+00, 9.90e-01, 9.17e-01, 8.57e-01, 8.01e-01, 7.48e-01, 6.96e-01, 6.44e-01, 5.89e-01, 5.24e-01, 4.51e-01, 3.71e-01, 2.99e-01, 2.45e-01, 2.00e-01, 1.66e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.40e-01, 1.30e-01, 1.20e-01, 1.10e-01, 9.50e-02, 6.00e-02, 3.00e-02,
                              1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.69e+00, 1.67e+00, 1.65e+00, 1.63e+00, 1.62e+00, 1.58e+00, 1.54e+00, 1.51e+00, 1.47e+00, 1.43e+00, 1.39e+00, 1.34e+00, 1.29e+00, 1.23e+00, 1.16e+00, 1.08e+00, 1.01e+00, 9.56e-01, 9.01e-01, 8.48e-01, 7.96e-01, 7.45e-01, 6.94e-01, 6.43e-01, 5.88e-01, 5.24e-01, 4.51e-01, 3.71e-01, 3.00e-01, 2.45e-01, 1.98e-01, 1.59e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.40e-01, 1.30e-01, 1.20e-01, 1.10e-01, 9.50e-02, 6.00e-02, 3.00e-02,
                              1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.70e+00, 1.69e+00, 1.69e+00, 1.68e+00, 1.66e+00, 1.65e+00, 1.63e+00, 1.61e+00, 1.58e+00, 1.55e+00, 1.52e+00, 1.48e+00, 1.42e+00, 1.36e+00, 1.27e+00, 1.19e+00, 1.12e+00, 1.06e+00, 9.87e-01, 9.14e-01, 8.30e-01, 7.46e-01, 6.62e-01, 5.64e-01, 4.61e-01, 3.63e-01, 2.77e-01, 2.10e-01, 1.65e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.50e-01, 1.40e-01, 1.30e-01, 1.20e-01, 1.10e-01, 9.50e-02, 6.00e-02, 3.00e-02},
	O2_ppmv[nz_mod] = {/* ppmv for the HITRAN molecule #7 (oxygen), sezonaly invariant: p.25, Sec.2.2.2, Table 2*/
	                   2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.09e+05, 2.00e+05, 1.90e+05, 1.80e+05, 1.60e+05, 1.40e+05, 1.20e+05, 9.40e+04, 7.25e+04},
	NO2_ppmv[nz_mod] = {/* ppmv for the HITRAN molecule #10 (nitrogen dioxide), sezonaly invariant: p.25, Sec.2.2.2, Table 2*/
                        2.30e-05, 2.30e-05, 2.30e-05, 2.30e-05, 2.30e-05, 2.30e-05, 2.30e-05, 2.30e-05, 2.30e-05, 2.32e-05, 2.38e-05, 2.62e-05, 3.15e-05, 4.45e-05, 7.48e-05, 1.71e-04, 3.19e-04, 5.19e-04, 7.71e-04, 1.06e-03, 1.39e-03, 1.76e-03, 2.16e-03, 2.58e-03, 3.06e-03, 3.74e-03, 4.81e-03, 6.16e-03, 7.21e-03, 7.28e-03, 6.26e-03, 4.03e-03, 2.17e-03, 1.15e-03, 6.66e-04, 4.43e-04, 3.39e-04, 2.85e-04, 2.53e-04, 2.31e-04, 2.15e-04, 2.02e-04, 1.92e-04, 1.83e-04, 1.76e-04, 1.70e-04, 1.64e-04, 1.59e-04, 1.55e-04, 1.51e-04};
/*------------------------------------------------------------------------------------------------*/