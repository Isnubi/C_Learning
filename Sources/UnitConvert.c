#include <math.h>

void CelsiusToFahrenheit(float *Celsius, float *Fahrenheit)
{
    *Fahrenheit = *Celsius * 1.8 + 32;
}

void FahrenheitToCelsius(float *Fahrenheit, float *Celsius)
{
    *Celsius = (*Fahrenheit - 32) / 1.8;
}

void metersToKilometers(float *meters, float *kilometers)
{
    *kilometers = *meters / 1000;
}

void kilometersToMeters(float *kilometers, float *meters)
{
    *meters = *kilometers * 1000;
}

void kilogramsToPounds(float *kilograms, float *pounds)
{
    *pounds = *kilograms * 2.2;
}

void poundsToKilograms(float *pounds, float *kilograms)
{
    *kilograms = *pounds / 2.2;
}

