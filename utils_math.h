#pragma once
#include "utils.h"
#include <math.h>
#include <complex.h>
#include <stdio.h>
//use #define UTILS_MATH_IMPLEMENTATION to compile


typedef struct{
 double x;
 double y;
}vector2d;
vector2d vector2dAdd(vector2d a, vector2d b);
vector2d vector2dSub(vector2d a, vector2d b);
double vector2dDot(vector2d a, vector2d b);
vector2d vector2dScale(double s, vector2d a);
double vector2dLen(vector2d a);
vector2d vector2dNormalize(vector2d a);
double vector2dAngle(vector2d a, vector2d b);
void vector2dprint(vector2d v);


typedef struct{
 double x;
 double y;
 double z;
}vector3d;
vector3d vector3dAdd(vector3d a, vector3d b);
vector3d vector3dSub(vector3d a, vector3d b);
double vector3dDot(vector3d a, vector3d b);
vector3d vector3dScale(double s, vector3d a);
double vector3dLen(vector3d a);
vector3d vector3dNormalize(vector3d a);
double vector3dAngle(vector3d a, vector3d b);
void vector3dprint(vector3d v);


typedef struct{
 double w;
 double x;
 double y;
 double z;
}vector4d;
vector4d vector4dAdd(vector4d a, vector4d b);
vector4d vector4dSub(vector4d a, vector4d b);
double vector4dDot(vector4d a, vector4d b);
vector4d vector4dScale(double s, vector4d a);
double vector4dLen(vector4d a);
vector4d vector4dNormalize(vector4d a);
double vector4dAngle(vector4d a, vector4d b);
void vector4dprint(vector4d v);


typedef struct{
    double x0;
    double x1;
    double x2;
    double x3;
    double x4;
}vector5d;
vector5d vector5dAdd(vector5d a, vector5d b);
vector5d vector5dSub(vector5d a, vector5d b);
double vector5dDot(vector5d a, vector5d b);
vector5d vector5dScale(double s, vector5d a);
double vector5dLen(vector5d a);
vector5d vector5dNormalize(vector5d a);
double vector5dAngle(vector5d a, vector5d b);
void vector5dprint(vector5d v);


typedef struct{
    double x0;
    double x1;
    double x2;
    double x3;
    double x4;
    double x5;
}vector6d;
vector6d vector6dAdd(vector6d a, vector6d b);
vector6d vector6dSub(vector6d a, vector6d b);
double vector6dDot(vector6d a, vector6d b);
vector6d vector6dScale(double s, vector6d a);
double vector6dLen(vector6d a);
vector6d vector6dNormalize(vector6d a);
double vector6dAngle(vector6d a, vector6d b);
void vector6dprint(vector6d v);


typedef struct{
    double x0;
    double x1;
    double x2;
    double x3;
    double x4;
    double x5;
    double x6;
}vector7d;
vector7d vector7dAdd(vector7d a, vector7d b);
vector7d vector7dSub(vector7d a, vector7d b);
double vector7dDot(vector7d a, vector7d b);
vector7d vector7dScale(double s, vector7d a);
double vector7dLen(vector7d a);
vector7d vector7dNormalize(vector7d a);
double vector7dAngle(vector7d a, vector7d b);
void vector7dprint(vector7d v);


typedef struct{
    double x0;
    double x1;
    double x2;
    double x3;
    double x4;
    double x5;
    double x6;
    double x7;
}vector8d;
vector8d vector8dAdd(vector8d a, vector8d b);
vector8d vector8dSub(vector8d a, vector8d b);
double vector8dDot(vector8d a, vector8d b);
vector8d vector8dScale(double s, vector8d a);
double vector8dLen(vector8d a);
vector8d vector8dNormalize(vector8d a);
double vector8dAngle(vector8d a, vector8d b);
void vector8dprint(vector8d v);


typedef struct{
    double x0;
    double x1;
    double x2;
    double x3;
    double x4;
    double x5;
    double x6;
    double x7;
    double x8;
}vector9d;
vector9d vector9dAdd(vector9d a, vector9d b);
vector9d vector9dSub(vector9d a, vector9d b);
double vector9dDot(vector9d a, vector9d b);
vector9d vector9dScale(double s, vector9d a);
double vector9dLen(vector9d a);
vector9d vector9dNormalize(vector9d a);
double vector9dAngle(vector9d a, vector9d b);
void vector9dprint(vector9d v);


typedef struct{
    double x0;
    double x1;
    double x2;
    double x3;
    double x4;
    double x5;
    double x6;
    double x7;
    double x8;
    double x9;
}vector10d;
vector10d vector10dAdd(vector10d a, vector10d b);
vector10d vector10dSub(vector10d a, vector10d b);
double vector10dDot(vector10d a, vector10d b);
vector10d vector10dScale(double s, vector10d a);
double vector10dLen(vector10d a);
vector10d vector10dNormalize(vector10d a);
double vector10dAngle(vector10d a, vector10d b);
void vector10dprint(vector10d v);

typedef struct {
  double data[2][2];
}matrix2x2d;
matrix2x2d matrix2x2dAdd(matrix2x2d a, matrix2x2d b);
matrix2x2d matrix2x2dSub(matrix2x2d a, matrix2x2d b);
matrix2x2d matrix2x2dMlt(matrix2x2d a, matrix2x2d b);
vector2d matrix2x2dMltVec(matrix2x2d a, vector2d b);
matrix2x2d matrix2x2dScale(double s, matrix2x2d a);
vector2d matrix2x2dRow(matrix2x2d m,int row);
vector2d matrix2x2dCol(matrix2x2d m, int col);
matrix2x2d matrix2x2dInverse(matrix2x2d a);
matrix2x2d matrix2x2dDeterminant(matrix2x2d a);
matrix2x2d matrix2x2dIdentity();
matrix2x2d matrix2x2dTranpose(matrix2x2d a);

typedef struct {
  double data[3][3];
}matrix3x3d;
matrix3x3d matrix3x3dAdd(matrix3x3d a, matrix3x3d b);
matrix3x3d matrix3x3dSub(matrix3x3d a, matrix3x3d b);
matrix3x3d matrix3x3dMlt(matrix3x3d a, matrix3x3d b);
vector3d matrix3x3dMltVec(matrix3x3d a, vector3d b);
matrix3x3d matrix3x3dScale(double s, matrix3x3d a);
vector3d matrix3x3dRow(matrix3x3d m,int row);
vector3d matrix3x3dCol(matrix3x3d m, int col);
matrix3x3d matrix3x3dInverse(matrix3x3d a);
matrix3x3d matrix3x3dDeterminant(matrix3x3d a);
matrix3x3d matrix3x3dIdentity();
matrix3x3d matrix3x3dTranpose(matrix3x3d a);

typedef struct {
  double data[4][4];
}matrix4x4d;
matrix4x4d matrix4x4dAdd(matrix4x4d a, matrix4x4d b);
matrix4x4d matrix4x4dSub(matrix4x4d a, matrix4x4d b);
matrix4x4d matrix4x4dMlt(matrix4x4d a, matrix4x4d b);
vector4d matrix4x4dMltVec(matrix4x4d a, vector4d b);
matrix4x4d matrix4x4dScale(double s, matrix4x4d a);
vector4d matrix4x4dRow(matrix4x4d m,int row);
vector4d matrix4x4dCol(matrix4x4d m, int col);
matrix4x4d matrix4x4dInverse(matrix4x4d a);
matrix4x4d matrix4x4dDeterminant(matrix4x4d a);
matrix4x4d matrix4x4dIdentity();
matrix4x4d matrix4x4dTranpose(matrix4x4d a);

typedef struct {
  double data[5][5];
}matrix5x5d;
matrix5x5d matrix5x5dAdd(matrix5x5d a, matrix5x5d b);
matrix5x5d matrix5x5dSub(matrix5x5d a, matrix5x5d b);
matrix5x5d matrix5x5dMlt(matrix5x5d a, matrix5x5d b);
vector5d matrix5x5dMltVec(matrix5x5d a, vector5d b);
matrix5x5d matrix5x5dScale(double s, matrix5x5d a);
vector5d matrix5x5dRow(matrix5x5d m,int row);
vector5d matrix5x5dCol(matrix5x5d m, int col);
matrix5x5d matrix5x5dInverse(matrix5x5d a);
matrix5x5d matrix5x5dDeterminant(matrix5x5d a);
matrix5x5d matrix5x5dIdentity();
matrix5x5d matrix5x5dTranpose(matrix5x5d a);

typedef struct {
  double data[6][6];
}matrix6x6d;
matrix6x6d matrix6x6dAdd(matrix6x6d a, matrix6x6d b);
matrix6x6d matrix6x6dSub(matrix6x6d a, matrix6x6d b);
matrix6x6d matrix6x6dMlt(matrix6x6d a, matrix6x6d b);
vector6d matrix6x6dMltVec(matrix6x6d a, vector6d b);
matrix6x6d matrix6x6dScale(double s, matrix6x6d a);
vector6d matrix6x6dRow(matrix6x6d m,int row);
vector6d matrix6x6dCol(matrix6x6d m, int col);
matrix6x6d matrix6x6dInverse(matrix6x6d a);
matrix6x6d matrix6x6dDeterminant(matrix6x6d a);
matrix6x6d matrix6x6dIdentity();
matrix6x6d matrix6x6dTranpose(matrix6x6d a);

typedef struct {
  double data[7][7];
}matrix7x7d;
matrix7x7d matrix7x7dAdd(matrix7x7d a, matrix7x7d b);
matrix7x7d matrix7x7dSub(matrix7x7d a, matrix7x7d b);
matrix7x7d matrix7x7dMlt(matrix7x7d a, matrix7x7d b);
vector7d matrix7x7dMltVec(matrix7x7d a, vector7d b);
matrix7x7d matrix7x7dScale(double s, matrix7x7d a);
vector7d matrix7x7dRow(matrix7x7d m,int row);
vector7d matrix7x7dCol(matrix7x7d m, int col);
matrix7x7d matrix7x7dInverse(matrix7x7d a);
matrix7x7d matrix7x7dDeterminant(matrix7x7d a);
matrix7x7d matrix7x7dIdentity();
matrix7x7d matrix7x7dTranpose(matrix7x7d a);

typedef struct {
  double data[8][8];
}matrix8x8d;
matrix8x8d matrix8x8dAdd(matrix8x8d a, matrix8x8d b);
matrix8x8d matrix8x8dSub(matrix8x8d a, matrix8x8d b);
matrix8x8d matrix8x8dMlt(matrix8x8d a, matrix8x8d b);
vector8d matrix8x8dMltVec(matrix8x8d a, vector8d b);
matrix8x8d matrix8x8dScale(double s, matrix8x8d a);
vector8d matrix8x8dRow(matrix8x8d m,int row);
vector8d matrix8x8dCol(matrix8x8d m, int col);
matrix8x8d matrix8x8dInverse(matrix8x8d a);
matrix8x8d matrix8x8dDeterminant(matrix8x8d a);
matrix8x8d matrix8x8dIdentity();
matrix8x8d matrix8x8dTranpose(matrix8x8d a);

typedef struct {
  double data[9][9];
}matrix9x9d;
matrix9x9d matrix9x9dAdd(matrix9x9d a, matrix9x9d b);
matrix9x9d matrix9x9dSub(matrix9x9d a, matrix9x9d b);
matrix9x9d matrix9x9dMlt(matrix9x9d a, matrix9x9d b);
vector9d matrix9x9dMltVec(matrix9x9d a, vector9d b);
matrix9x9d matrix9x9dScale(double s, matrix9x9d a);
vector9d matrix9x9dRow(matrix9x9d m,int row);
vector9d matrix9x9dCol(matrix9x9d m, int col);
matrix9x9d matrix9x9dInverse(matrix9x9d a);
matrix9x9d matrix9x9dDeterminant(matrix9x9d a);
matrix9x9d matrix9x9dIdentity();
matrix9x9d matrix9x9dTranpose(matrix9x9d a);

typedef struct {
  double data[10][10];
}matrix10x10d;
matrix10x10d matrix10x10dAdd(matrix10x10d a, matrix10x10d b);
matrix10x10d matrix10x10dSub(matrix10x10d a, matrix10x10d b);
matrix10x10d matrix10x10dMlt(matrix10x10d a, matrix10x10d b);
vector10d matrix10x10dMltVec(matrix10x10d a, vector10d b);
matrix10x10d matrix10x10dScale(double s, matrix10x10d a);
vector10d matrix10x10dRow(matrix10x10d m,int row);
vector10d matrix10x10dCol(matrix10x10d m, int col);
matrix10x10d matrix10x10dInverse(matrix10x10d a);
matrix10x10d matrix10x10dDeterminant(matrix10x10d a);
matrix10x10d matrix10x10dIdentity();
matrix10x10d matrix10x10dTranpose(matrix10x10d a);


typedef struct{
 float x;
 float y;
}vector2f;
vector2f vector2fAdd(vector2f a, vector2f b);
vector2f vector2fSub(vector2f a, vector2f b);
float vector2fDot(vector2f a, vector2f b);
vector2f vector2fScale(float s, vector2f a);
float vector2fLen(vector2f a);
vector2f vector2fNormalize(vector2f a);
float vector2fAngle(vector2f a, vector2f b);
void vector2fprint(vector2f v);


typedef struct{
 float x;
 float y;
 float z;
}vector3f;
vector3f vector3fAdd(vector3f a, vector3f b);
vector3f vector3fSub(vector3f a, vector3f b);
float vector3fDot(vector3f a, vector3f b);
vector3f vector3fScale(float s, vector3f a);
float vector3fLen(vector3f a);
vector3f vector3fNormalize(vector3f a);
float vector3fAngle(vector3f a, vector3f b);
void vector3fprint(vector3f v);


typedef struct{
 float w;
 float x;
 float y;
 float z;
}vector4f;
vector4f vector4fAdd(vector4f a, vector4f b);
vector4f vector4fSub(vector4f a, vector4f b);
float vector4fDot(vector4f a, vector4f b);
vector4f vector4fScale(float s, vector4f a);
float vector4fLen(vector4f a);
vector4f vector4fNormalize(vector4f a);
float vector4fAngle(vector4f a, vector4f b);
void vector4fprint(vector4f v);


typedef struct{
    float x0;
    float x1;
    float x2;
    float x3;
    float x4;
}vector5f;
vector5f vector5fAdd(vector5f a, vector5f b);
vector5f vector5fSub(vector5f a, vector5f b);
float vector5fDot(vector5f a, vector5f b);
vector5f vector5fScale(float s, vector5f a);
float vector5fLen(vector5f a);
vector5f vector5fNormalize(vector5f a);
float vector5fAngle(vector5f a, vector5f b);
void vector5fprint(vector5f v);


typedef struct{
    float x0;
    float x1;
    float x2;
    float x3;
    float x4;
    float x5;
}vector6f;
vector6f vector6fAdd(vector6f a, vector6f b);
vector6f vector6fSub(vector6f a, vector6f b);
float vector6fDot(vector6f a, vector6f b);
vector6f vector6fScale(float s, vector6f a);
float vector6fLen(vector6f a);
vector6f vector6fNormalize(vector6f a);
float vector6fAngle(vector6f a, vector6f b);
void vector6fprint(vector6f v);


typedef struct{
    float x0;
    float x1;
    float x2;
    float x3;
    float x4;
    float x5;
    float x6;
}vector7f;
vector7f vector7fAdd(vector7f a, vector7f b);
vector7f vector7fSub(vector7f a, vector7f b);
float vector7fDot(vector7f a, vector7f b);
vector7f vector7fScale(float s, vector7f a);
float vector7fLen(vector7f a);
vector7f vector7fNormalize(vector7f a);
float vector7fAngle(vector7f a, vector7f b);
void vector7fprint(vector7f v);


typedef struct{
    float x0;
    float x1;
    float x2;
    float x3;
    float x4;
    float x5;
    float x6;
    float x7;
}vector8f;
vector8f vector8fAdd(vector8f a, vector8f b);
vector8f vector8fSub(vector8f a, vector8f b);
float vector8fDot(vector8f a, vector8f b);
vector8f vector8fScale(float s, vector8f a);
float vector8fLen(vector8f a);
vector8f vector8fNormalize(vector8f a);
float vector8fAngle(vector8f a, vector8f b);
void vector8fprint(vector8f v);


typedef struct{
    float x0;
    float x1;
    float x2;
    float x3;
    float x4;
    float x5;
    float x6;
    float x7;
    float x8;
}vector9f;
vector9f vector9fAdd(vector9f a, vector9f b);
vector9f vector9fSub(vector9f a, vector9f b);
float vector9fDot(vector9f a, vector9f b);
vector9f vector9fScale(float s, vector9f a);
float vector9fLen(vector9f a);
vector9f vector9fNormalize(vector9f a);
float vector9fAngle(vector9f a, vector9f b);
void vector9fprint(vector9f v);


typedef struct{
    float x0;
    float x1;
    float x2;
    float x3;
    float x4;
    float x5;
    float x6;
    float x7;
    float x8;
    float x9;
}vector10f;
vector10f vector10fAdd(vector10f a, vector10f b);
vector10f vector10fSub(vector10f a, vector10f b);
float vector10fDot(vector10f a, vector10f b);
vector10f vector10fScale(float s, vector10f a);
float vector10fLen(vector10f a);
vector10f vector10fNormalize(vector10f a);
float vector10fAngle(vector10f a, vector10f b);
void vector10fprint(vector10f v);

typedef struct {
  float data[2][2];
}matrix2x2f;
matrix2x2f matrix2x2fAdd(matrix2x2f a, matrix2x2f b);
matrix2x2f matrix2x2fSub(matrix2x2f a, matrix2x2f b);
matrix2x2f matrix2x2fMlt(matrix2x2f a, matrix2x2f b);
vector2f matrix2x2fMltVec(matrix2x2f a, vector2f b);
matrix2x2f matrix2x2fScale(float s, matrix2x2f a);
vector2f matrix2x2fRow(matrix2x2f m,int row);
vector2f matrix2x2fCol(matrix2x2f m, int col);
matrix2x2f matrix2x2fInverse(matrix2x2f a);
matrix2x2f matrix2x2fDeterminant(matrix2x2f a);
matrix2x2f matrix2x2fIdentity();
matrix2x2f matrix2x2fTranpose(matrix2x2f a);

typedef struct {
  float data[3][3];
}matrix3x3f;
matrix3x3f matrix3x3fAdd(matrix3x3f a, matrix3x3f b);
matrix3x3f matrix3x3fSub(matrix3x3f a, matrix3x3f b);
matrix3x3f matrix3x3fMlt(matrix3x3f a, matrix3x3f b);
vector3f matrix3x3fMltVec(matrix3x3f a, vector3f b);
matrix3x3f matrix3x3fScale(float s, matrix3x3f a);
vector3f matrix3x3fRow(matrix3x3f m,int row);
vector3f matrix3x3fCol(matrix3x3f m, int col);
matrix3x3f matrix3x3fInverse(matrix3x3f a);
matrix3x3f matrix3x3fDeterminant(matrix3x3f a);
matrix3x3f matrix3x3fIdentity();
matrix3x3f matrix3x3fTranpose(matrix3x3f a);

typedef struct {
  float data[4][4];
}matrix4x4f;
matrix4x4f matrix4x4fAdd(matrix4x4f a, matrix4x4f b);
matrix4x4f matrix4x4fSub(matrix4x4f a, matrix4x4f b);
matrix4x4f matrix4x4fMlt(matrix4x4f a, matrix4x4f b);
vector4f matrix4x4fMltVec(matrix4x4f a, vector4f b);
matrix4x4f matrix4x4fScale(float s, matrix4x4f a);
vector4f matrix4x4fRow(matrix4x4f m,int row);
vector4f matrix4x4fCol(matrix4x4f m, int col);
matrix4x4f matrix4x4fInverse(matrix4x4f a);
matrix4x4f matrix4x4fDeterminant(matrix4x4f a);
matrix4x4f matrix4x4fIdentity();
matrix4x4f matrix4x4fTranpose(matrix4x4f a);

typedef struct {
  float data[5][5];
}matrix5x5f;
matrix5x5f matrix5x5fAdd(matrix5x5f a, matrix5x5f b);
matrix5x5f matrix5x5fSub(matrix5x5f a, matrix5x5f b);
matrix5x5f matrix5x5fMlt(matrix5x5f a, matrix5x5f b);
vector5f matrix5x5fMltVec(matrix5x5f a, vector5f b);
matrix5x5f matrix5x5fScale(float s, matrix5x5f a);
vector5f matrix5x5fRow(matrix5x5f m,int row);
vector5f matrix5x5fCol(matrix5x5f m, int col);
matrix5x5f matrix5x5fInverse(matrix5x5f a);
matrix5x5f matrix5x5fDeterminant(matrix5x5f a);
matrix5x5f matrix5x5fIdentity();
matrix5x5f matrix5x5fTranpose(matrix5x5f a);

typedef struct {
  float data[6][6];
}matrix6x6f;
matrix6x6f matrix6x6fAdd(matrix6x6f a, matrix6x6f b);
matrix6x6f matrix6x6fSub(matrix6x6f a, matrix6x6f b);
matrix6x6f matrix6x6fMlt(matrix6x6f a, matrix6x6f b);
vector6f matrix6x6fMltVec(matrix6x6f a, vector6f b);
matrix6x6f matrix6x6fScale(float s, matrix6x6f a);
vector6f matrix6x6fRow(matrix6x6f m,int row);
vector6f matrix6x6fCol(matrix6x6f m, int col);
matrix6x6f matrix6x6fInverse(matrix6x6f a);
matrix6x6f matrix6x6fDeterminant(matrix6x6f a);
matrix6x6f matrix6x6fIdentity();
matrix6x6f matrix6x6fTranpose(matrix6x6f a);

typedef struct {
  float data[7][7];
}matrix7x7f;
matrix7x7f matrix7x7fAdd(matrix7x7f a, matrix7x7f b);
matrix7x7f matrix7x7fSub(matrix7x7f a, matrix7x7f b);
matrix7x7f matrix7x7fMlt(matrix7x7f a, matrix7x7f b);
vector7f matrix7x7fMltVec(matrix7x7f a, vector7f b);
matrix7x7f matrix7x7fScale(float s, matrix7x7f a);
vector7f matrix7x7fRow(matrix7x7f m,int row);
vector7f matrix7x7fCol(matrix7x7f m, int col);
matrix7x7f matrix7x7fInverse(matrix7x7f a);
matrix7x7f matrix7x7fDeterminant(matrix7x7f a);
matrix7x7f matrix7x7fIdentity();
matrix7x7f matrix7x7fTranpose(matrix7x7f a);

typedef struct {
  float data[8][8];
}matrix8x8f;
matrix8x8f matrix8x8fAdd(matrix8x8f a, matrix8x8f b);
matrix8x8f matrix8x8fSub(matrix8x8f a, matrix8x8f b);
matrix8x8f matrix8x8fMlt(matrix8x8f a, matrix8x8f b);
vector8f matrix8x8fMltVec(matrix8x8f a, vector8f b);
matrix8x8f matrix8x8fScale(float s, matrix8x8f a);
vector8f matrix8x8fRow(matrix8x8f m,int row);
vector8f matrix8x8fCol(matrix8x8f m, int col);
matrix8x8f matrix8x8fInverse(matrix8x8f a);
matrix8x8f matrix8x8fDeterminant(matrix8x8f a);
matrix8x8f matrix8x8fIdentity();
matrix8x8f matrix8x8fTranpose(matrix8x8f a);

typedef struct {
  float data[9][9];
}matrix9x9f;
matrix9x9f matrix9x9fAdd(matrix9x9f a, matrix9x9f b);
matrix9x9f matrix9x9fSub(matrix9x9f a, matrix9x9f b);
matrix9x9f matrix9x9fMlt(matrix9x9f a, matrix9x9f b);
vector9f matrix9x9fMltVec(matrix9x9f a, vector9f b);
matrix9x9f matrix9x9fScale(float s, matrix9x9f a);
vector9f matrix9x9fRow(matrix9x9f m,int row);
vector9f matrix9x9fCol(matrix9x9f m, int col);
matrix9x9f matrix9x9fInverse(matrix9x9f a);
matrix9x9f matrix9x9fDeterminant(matrix9x9f a);
matrix9x9f matrix9x9fIdentity();
matrix9x9f matrix9x9fTranpose(matrix9x9f a);

typedef struct {
  float data[10][10];
}matrix10x10f;
matrix10x10f matrix10x10fAdd(matrix10x10f a, matrix10x10f b);
matrix10x10f matrix10x10fSub(matrix10x10f a, matrix10x10f b);
matrix10x10f matrix10x10fMlt(matrix10x10f a, matrix10x10f b);
vector10f matrix10x10fMltVec(matrix10x10f a, vector10f b);
matrix10x10f matrix10x10fScale(float s, matrix10x10f a);
vector10f matrix10x10fRow(matrix10x10f m,int row);
vector10f matrix10x10fCol(matrix10x10f m, int col);
matrix10x10f matrix10x10fInverse(matrix10x10f a);
matrix10x10f matrix10x10fDeterminant(matrix10x10f a);
matrix10x10f matrix10x10fIdentity();
matrix10x10f matrix10x10fTranpose(matrix10x10f a);


typedef struct{
 int x;
 int y;
}vector2i;
vector2i vector2iAdd(vector2i a, vector2i b);
vector2i vector2iSub(vector2i a, vector2i b);
int vector2iDot(vector2i a, vector2i b);
vector2i vector2iScale(int s, vector2i a);
int vector2iLen(vector2i a);
vector2i vector2iNormalize(vector2i a);
int vector2iAngle(vector2i a, vector2i b);
void vector2iprint(vector2i v);


typedef struct{
 int x;
 int y;
 int z;
}vector3i;
vector3i vector3iAdd(vector3i a, vector3i b);
vector3i vector3iSub(vector3i a, vector3i b);
int vector3iDot(vector3i a, vector3i b);
vector3i vector3iScale(int s, vector3i a);
int vector3iLen(vector3i a);
vector3i vector3iNormalize(vector3i a);
int vector3iAngle(vector3i a, vector3i b);
void vector3iprint(vector3i v);


typedef struct{
 int w;
 int x;
 int y;
 int z;
}vector4i;
vector4i vector4iAdd(vector4i a, vector4i b);
vector4i vector4iSub(vector4i a, vector4i b);
int vector4iDot(vector4i a, vector4i b);
vector4i vector4iScale(int s, vector4i a);
int vector4iLen(vector4i a);
vector4i vector4iNormalize(vector4i a);
int vector4iAngle(vector4i a, vector4i b);
void vector4iprint(vector4i v);


typedef struct{
    int x0;
    int x1;
    int x2;
    int x3;
    int x4;
}vector5i;
vector5i vector5iAdd(vector5i a, vector5i b);
vector5i vector5iSub(vector5i a, vector5i b);
int vector5iDot(vector5i a, vector5i b);
vector5i vector5iScale(int s, vector5i a);
int vector5iLen(vector5i a);
vector5i vector5iNormalize(vector5i a);
int vector5iAngle(vector5i a, vector5i b);
void vector5iprint(vector5i v);


typedef struct{
    int x0;
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;
}vector6i;
vector6i vector6iAdd(vector6i a, vector6i b);
vector6i vector6iSub(vector6i a, vector6i b);
int vector6iDot(vector6i a, vector6i b);
vector6i vector6iScale(int s, vector6i a);
int vector6iLen(vector6i a);
vector6i vector6iNormalize(vector6i a);
int vector6iAngle(vector6i a, vector6i b);
void vector6iprint(vector6i v);


typedef struct{
    int x0;
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;
    int x6;
}vector7i;
vector7i vector7iAdd(vector7i a, vector7i b);
vector7i vector7iSub(vector7i a, vector7i b);
int vector7iDot(vector7i a, vector7i b);
vector7i vector7iScale(int s, vector7i a);
int vector7iLen(vector7i a);
vector7i vector7iNormalize(vector7i a);
int vector7iAngle(vector7i a, vector7i b);
void vector7iprint(vector7i v);


typedef struct{
    int x0;
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;
    int x6;
    int x7;
}vector8i;
vector8i vector8iAdd(vector8i a, vector8i b);
vector8i vector8iSub(vector8i a, vector8i b);
int vector8iDot(vector8i a, vector8i b);
vector8i vector8iScale(int s, vector8i a);
int vector8iLen(vector8i a);
vector8i vector8iNormalize(vector8i a);
int vector8iAngle(vector8i a, vector8i b);
void vector8iprint(vector8i v);


typedef struct{
    int x0;
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;
    int x6;
    int x7;
    int x8;
}vector9i;
vector9i vector9iAdd(vector9i a, vector9i b);
vector9i vector9iSub(vector9i a, vector9i b);
int vector9iDot(vector9i a, vector9i b);
vector9i vector9iScale(int s, vector9i a);
int vector9iLen(vector9i a);
vector9i vector9iNormalize(vector9i a);
int vector9iAngle(vector9i a, vector9i b);
void vector9iprint(vector9i v);


typedef struct{
    int x0;
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;
    int x6;
    int x7;
    int x8;
    int x9;
}vector10i;
vector10i vector10iAdd(vector10i a, vector10i b);
vector10i vector10iSub(vector10i a, vector10i b);
int vector10iDot(vector10i a, vector10i b);
vector10i vector10iScale(int s, vector10i a);
int vector10iLen(vector10i a);
vector10i vector10iNormalize(vector10i a);
int vector10iAngle(vector10i a, vector10i b);
void vector10iprint(vector10i v);

typedef struct {
  int data[2][2];
}matrix2x2i;
matrix2x2i matrix2x2iAdd(matrix2x2i a, matrix2x2i b);
matrix2x2i matrix2x2iSub(matrix2x2i a, matrix2x2i b);
matrix2x2i matrix2x2iMlt(matrix2x2i a, matrix2x2i b);
vector2i matrix2x2iMltVec(matrix2x2i a, vector2i b);
matrix2x2i matrix2x2iScale(int s, matrix2x2i a);
vector2i matrix2x2iRow(matrix2x2i m,int row);
vector2i matrix2x2iCol(matrix2x2i m, int col);
matrix2x2i matrix2x2iInverse(matrix2x2i a);
matrix2x2i matrix2x2iDeterminant(matrix2x2i a);
matrix2x2i matrix2x2iIdentity();
matrix2x2i matrix2x2iTranpose(matrix2x2i a);

typedef struct {
  int data[3][3];
}matrix3x3i;
matrix3x3i matrix3x3iAdd(matrix3x3i a, matrix3x3i b);
matrix3x3i matrix3x3iSub(matrix3x3i a, matrix3x3i b);
matrix3x3i matrix3x3iMlt(matrix3x3i a, matrix3x3i b);
vector3i matrix3x3iMltVec(matrix3x3i a, vector3i b);
matrix3x3i matrix3x3iScale(int s, matrix3x3i a);
vector3i matrix3x3iRow(matrix3x3i m,int row);
vector3i matrix3x3iCol(matrix3x3i m, int col);
matrix3x3i matrix3x3iInverse(matrix3x3i a);
matrix3x3i matrix3x3iDeterminant(matrix3x3i a);
matrix3x3i matrix3x3iIdentity();
matrix3x3i matrix3x3iTranpose(matrix3x3i a);

typedef struct {
  int data[4][4];
}matrix4x4i;
matrix4x4i matrix4x4iAdd(matrix4x4i a, matrix4x4i b);
matrix4x4i matrix4x4iSub(matrix4x4i a, matrix4x4i b);
matrix4x4i matrix4x4iMlt(matrix4x4i a, matrix4x4i b);
vector4i matrix4x4iMltVec(matrix4x4i a, vector4i b);
matrix4x4i matrix4x4iScale(int s, matrix4x4i a);
vector4i matrix4x4iRow(matrix4x4i m,int row);
vector4i matrix4x4iCol(matrix4x4i m, int col);
matrix4x4i matrix4x4iInverse(matrix4x4i a);
matrix4x4i matrix4x4iDeterminant(matrix4x4i a);
matrix4x4i matrix4x4iIdentity();
matrix4x4i matrix4x4iTranpose(matrix4x4i a);

typedef struct {
  int data[5][5];
}matrix5x5i;
matrix5x5i matrix5x5iAdd(matrix5x5i a, matrix5x5i b);
matrix5x5i matrix5x5iSub(matrix5x5i a, matrix5x5i b);
matrix5x5i matrix5x5iMlt(matrix5x5i a, matrix5x5i b);
vector5i matrix5x5iMltVec(matrix5x5i a, vector5i b);
matrix5x5i matrix5x5iScale(int s, matrix5x5i a);
vector5i matrix5x5iRow(matrix5x5i m,int row);
vector5i matrix5x5iCol(matrix5x5i m, int col);
matrix5x5i matrix5x5iInverse(matrix5x5i a);
matrix5x5i matrix5x5iDeterminant(matrix5x5i a);
matrix5x5i matrix5x5iIdentity();
matrix5x5i matrix5x5iTranpose(matrix5x5i a);

typedef struct {
  int data[6][6];
}matrix6x6i;
matrix6x6i matrix6x6iAdd(matrix6x6i a, matrix6x6i b);
matrix6x6i matrix6x6iSub(matrix6x6i a, matrix6x6i b);
matrix6x6i matrix6x6iMlt(matrix6x6i a, matrix6x6i b);
vector6i matrix6x6iMltVec(matrix6x6i a, vector6i b);
matrix6x6i matrix6x6iScale(int s, matrix6x6i a);
vector6i matrix6x6iRow(matrix6x6i m,int row);
vector6i matrix6x6iCol(matrix6x6i m, int col);
matrix6x6i matrix6x6iInverse(matrix6x6i a);
matrix6x6i matrix6x6iDeterminant(matrix6x6i a);
matrix6x6i matrix6x6iIdentity();
matrix6x6i matrix6x6iTranpose(matrix6x6i a);

typedef struct {
  int data[7][7];
}matrix7x7i;
matrix7x7i matrix7x7iAdd(matrix7x7i a, matrix7x7i b);
matrix7x7i matrix7x7iSub(matrix7x7i a, matrix7x7i b);
matrix7x7i matrix7x7iMlt(matrix7x7i a, matrix7x7i b);
vector7i matrix7x7iMltVec(matrix7x7i a, vector7i b);
matrix7x7i matrix7x7iScale(int s, matrix7x7i a);
vector7i matrix7x7iRow(matrix7x7i m,int row);
vector7i matrix7x7iCol(matrix7x7i m, int col);
matrix7x7i matrix7x7iInverse(matrix7x7i a);
matrix7x7i matrix7x7iDeterminant(matrix7x7i a);
matrix7x7i matrix7x7iIdentity();
matrix7x7i matrix7x7iTranpose(matrix7x7i a);

typedef struct {
  int data[8][8];
}matrix8x8i;
matrix8x8i matrix8x8iAdd(matrix8x8i a, matrix8x8i b);
matrix8x8i matrix8x8iSub(matrix8x8i a, matrix8x8i b);
matrix8x8i matrix8x8iMlt(matrix8x8i a, matrix8x8i b);
vector8i matrix8x8iMltVec(matrix8x8i a, vector8i b);
matrix8x8i matrix8x8iScale(int s, matrix8x8i a);
vector8i matrix8x8iRow(matrix8x8i m,int row);
vector8i matrix8x8iCol(matrix8x8i m, int col);
matrix8x8i matrix8x8iInverse(matrix8x8i a);
matrix8x8i matrix8x8iDeterminant(matrix8x8i a);
matrix8x8i matrix8x8iIdentity();
matrix8x8i matrix8x8iTranpose(matrix8x8i a);

typedef struct {
  int data[9][9];
}matrix9x9i;
matrix9x9i matrix9x9iAdd(matrix9x9i a, matrix9x9i b);
matrix9x9i matrix9x9iSub(matrix9x9i a, matrix9x9i b);
matrix9x9i matrix9x9iMlt(matrix9x9i a, matrix9x9i b);
vector9i matrix9x9iMltVec(matrix9x9i a, vector9i b);
matrix9x9i matrix9x9iScale(int s, matrix9x9i a);
vector9i matrix9x9iRow(matrix9x9i m,int row);
vector9i matrix9x9iCol(matrix9x9i m, int col);
matrix9x9i matrix9x9iInverse(matrix9x9i a);
matrix9x9i matrix9x9iDeterminant(matrix9x9i a);
matrix9x9i matrix9x9iIdentity();
matrix9x9i matrix9x9iTranpose(matrix9x9i a);

typedef struct {
  int data[10][10];
}matrix10x10i;
matrix10x10i matrix10x10iAdd(matrix10x10i a, matrix10x10i b);
matrix10x10i matrix10x10iSub(matrix10x10i a, matrix10x10i b);
matrix10x10i matrix10x10iMlt(matrix10x10i a, matrix10x10i b);
vector10i matrix10x10iMltVec(matrix10x10i a, vector10i b);
matrix10x10i matrix10x10iScale(int s, matrix10x10i a);
vector10i matrix10x10iRow(matrix10x10i m,int row);
vector10i matrix10x10iCol(matrix10x10i m, int col);
matrix10x10i matrix10x10iInverse(matrix10x10i a);
matrix10x10i matrix10x10iDeterminant(matrix10x10i a);
matrix10x10i matrix10x10iIdentity();
matrix10x10i matrix10x10iTranpose(matrix10x10i a);

#ifdef UTILS_MATH_IMPLEMENTATION
vector2d vector2dAdd(vector2d a, vector2d b){
  return (vector2d){a.x +b.x, a.y+b.y};
}
vector2d vector2dSub(vector2d a, vector2d b){
  return (vector2d){a.x-b.x, a.y-b.y};
}
vector2d vector2dScale(double s, vector2d a){
  return (vector2d){a.x*s, a.y*s};
}
double vector2dDot(vector2d a, vector2d b){
  return a.x*b.x+a.y*b.y;
}
double vector2dLen(vector2d a){
  return sqrt(a.x*a.x+a.y*a.y);
}
vector2d vector2dNormalize(vector2d a){return vector2dScale(1/vector2dLen(a),a);}
double vector2dAngle(vector2d a, vector2d b){a = vector2dNormalize(a); b = vector2dNormalize(b);return acos(vector2dDot(a,b));}
void vector2dprint(vector2d v){
  printf("%lf, %lf", v.x, v.y);
}
vector3d vector3dAdd(vector3d a, vector3d b){
  return (vector3d){a.x +b.x, a.y+b.y, a.z+b.z};
}
vector3d vector3dSub(vector3d a, vector3d b){
  return (vector3d){a.x-b.x, a.y-b.y, a.z-b.z};
}
vector3d vector3dScale(double s, vector3d a){
  return (vector3d){a.x*s, a.y*s, a.z*s};
}
double vector3dDot(vector3d a, vector3d b){
  return a.x*b.x+a.y*b.y+a.z*b.z;
}
double vector3dLen(vector3d a){
  return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}
vector3d vector3dNormalize(vector3d a){return vector3dScale(1/vector3dLen(a),a);}
double vector3dAngle(vector3d a, vector3d b){a = vector3dNormalize(a); b = vector3dNormalize(b);return acos(vector3dDot(a,b));}
void vector3dprint(vector3d v){
  printf("%lf, %lf, %lf", v.x, v.y, v.z);
}
vector4d vector4dAdd(vector4d a, vector4d b){
  return (vector4d){a.w+b.w,a.x+b.x, a.y+b.y, a.z+b.z};
}
vector4d vector4dSub(vector4d a, vector4d b){
  return (vector4d){a.w-b.w,a.x-b.x, a.y-b.y, a.z-b.z};
}
vector4d vector4dScale(double s, vector4d a){
  return (vector4d){a.w*s,a.x*s, a.y*s, a.z*s};
}
double vector4dDot(vector4d a, vector4d b){
  return a.w*b.w+a.x*b.x+a.y*b.y+a.z*b.z;
}
double vector4dLen(vector4d a){
  return sqrt(a.w*a.w+a.x*a.x+a.y*a.y+a.z*a.z);
}
vector4d vector4dNormalize(vector4d a){return vector4dScale(1/vector4dLen(a),a);}
double vector4dAngle(vector4d a, vector4d b){a = vector4dNormalize(a); b = vector4dNormalize(b);return acos(vector4dDot(a,b));}
void vector4dprint(vector4d v){
  printf("%lf, %lf, %lf, %lf", v.w,v.x, v.y, v.z);
}
vector5d vector5dAdd(vector5d a, vector5d b){
  vector5d out;
  out.x0 = a.x0+b.x0;
  out.x1 = a.x1+b.x1;
  out.x2 = a.x2+b.x2;
  out.x3 = a.x3+b.x3;
  out.x4 = a.x4+b.x4;
  return out;
}
vector5d vector5dSub(vector5d a, vector5d b){
  vector5d out;
  out.x0 = a.x0-b.x0;
  out.x1 = a.x1-b.x1;
  out.x2 = a.x2-b.x2;
  out.x3 = a.x3-b.x3;
  out.x4 = a.x4-b.x4;
  return out;
}
vector5d vector5dScale(double s,vector5d a){
  vector5d out;
  out.x0 = s*a.x0;
  out.x1 = s*a.x1;
  out.x2 = s*a.x2;
  out.x3 = s*a.x3;
  out.x4 = s*a.x4;
  return out;
}
double vector5dDot(vector5d a, vector5d b){
  double out = 0;
  out += a.x0*b.x0;
  out += a.x1*b.x1;
  out += a.x2*b.x2;
  out += a.x3*b.x3;
  out += a.x4*b.x4;
  return out;
}
double vector5dLen(vector5d a){
  double out = 0;
  out += a.x0*a.x0;
  out += a.x1*a.x1;
  out += a.x2*a.x2;
  out += a.x3*a.x3;
  out += a.x4*a.x4;
  return sqrt(out);
}
vector5d vector5dNormalize(vector5d a){return vector5dScale(1/vector5dLen(a),a);}
double vector5dAngle(vector5d a, vector5d b){a = vector5dNormalize(a); b = vector5dNormalize(b);return acos(vector5dDot(a,b));}
void vector5dprint(vector5d v){
  printf("%lf, %lf, %lf, %lf, %lf",v.x0, v.x1, v.x2, v.x3, v.x4);
}
 
vector6d vector6dAdd(vector6d a, vector6d b){
  vector6d out;
  out.x0 = a.x0+b.x0;
  out.x1 = a.x1+b.x1;
  out.x2 = a.x2+b.x2;
  out.x3 = a.x3+b.x3;
  out.x4 = a.x4+b.x4;
  out.x5 = a.x5+b.x5;
  return out;
}
vector6d vector6dSub(vector6d a, vector6d b){
  vector6d out;
  out.x0 = a.x0-b.x0;
  out.x1 = a.x1-b.x1;
  out.x2 = a.x2-b.x2;
  out.x3 = a.x3-b.x3;
  out.x4 = a.x4-b.x4;
  out.x5 = a.x5-b.x5;
  return out;
}
vector6d vector6dScale(double s,vector6d a){
  vector6d out;
  out.x0 = s*a.x0;
  out.x1 = s*a.x1;
  out.x2 = s*a.x2;
  out.x3 = s*a.x3;
  out.x4 = s*a.x4;
  out.x5 = s*a.x5;
  return out;
}
double vector6dDot(vector6d a, vector6d b){
  double out = 0;
  out += a.x0*b.x0;
  out += a.x1*b.x1;
  out += a.x2*b.x2;
  out += a.x3*b.x3;
  out += a.x4*b.x4;
  out += a.x5*b.x5;
  return out;
}
double vector6dLen(vector6d a){
  double out = 0;
  out += a.x0*a.x0;
  out += a.x1*a.x1;
  out += a.x2*a.x2;
  out += a.x3*a.x3;
  out += a.x4*a.x4;
  out += a.x5*a.x5;
  return sqrt(out);
}
vector6d vector6dNormalize(vector6d a){return vector6dScale(1/vector6dLen(a),a);}
double vector6dAngle(vector6d a, vector6d b){a = vector6dNormalize(a); b = vector6dNormalize(b);return acos(vector6dDot(a,b));}
void vector6dprint(vector6d v){
  printf("%lf, %lf, %lf, %lf, %lf, %lf",v.x0, v.x1, v.x2, v.x3, v.x4, v.x5);
}
 
vector7d vector7dAdd(vector7d a, vector7d b){
  vector7d out;
  out.x0 = a.x0+b.x0;
  out.x1 = a.x1+b.x1;
  out.x2 = a.x2+b.x2;
  out.x3 = a.x3+b.x3;
  out.x4 = a.x4+b.x4;
  out.x5 = a.x5+b.x5;
  out.x6 = a.x6+b.x6;
  return out;
}
vector7d vector7dSub(vector7d a, vector7d b){
  vector7d out;
  out.x0 = a.x0-b.x0;
  out.x1 = a.x1-b.x1;
  out.x2 = a.x2-b.x2;
  out.x3 = a.x3-b.x3;
  out.x4 = a.x4-b.x4;
  out.x5 = a.x5-b.x5;
  out.x6 = a.x6-b.x6;
  return out;
}
vector7d vector7dScale(double s,vector7d a){
  vector7d out;
  out.x0 = s*a.x0;
  out.x1 = s*a.x1;
  out.x2 = s*a.x2;
  out.x3 = s*a.x3;
  out.x4 = s*a.x4;
  out.x5 = s*a.x5;
  out.x6 = s*a.x6;
  return out;
}
double vector7dDot(vector7d a, vector7d b){
  double out = 0;
  out += a.x0*b.x0;
  out += a.x1*b.x1;
  out += a.x2*b.x2;
  out += a.x3*b.x3;
  out += a.x4*b.x4;
  out += a.x5*b.x5;
  out += a.x6*b.x6;
  return out;
}
double vector7dLen(vector7d a){
  double out = 0;
  out += a.x0*a.x0;
  out += a.x1*a.x1;
  out += a.x2*a.x2;
  out += a.x3*a.x3;
  out += a.x4*a.x4;
  out += a.x5*a.x5;
  out += a.x6*a.x6;
  return sqrt(out);
}
vector7d vector7dNormalize(vector7d a){return vector7dScale(1/vector7dLen(a),a);}
double vector7dAngle(vector7d a, vector7d b){a = vector7dNormalize(a); b = vector7dNormalize(b);return acos(vector7dDot(a,b));}
void vector7dprint(vector7d v){
  printf("%lf, %lf, %lf, %lf, %lf, %lf, %lf",v.x0, v.x1, v.x2, v.x3, v.x4, v.x5, v.x6);
}
 
vector8d vector8dAdd(vector8d a, vector8d b){
  vector8d out;
  out.x0 = a.x0+b.x0;
  out.x1 = a.x1+b.x1;
  out.x2 = a.x2+b.x2;
  out.x3 = a.x3+b.x3;
  out.x4 = a.x4+b.x4;
  out.x5 = a.x5+b.x5;
  out.x6 = a.x6+b.x6;
  out.x7 = a.x7+b.x7;
  return out;
}
vector8d vector8dSub(vector8d a, vector8d b){
  vector8d out;
  out.x0 = a.x0-b.x0;
  out.x1 = a.x1-b.x1;
  out.x2 = a.x2-b.x2;
  out.x3 = a.x3-b.x3;
  out.x4 = a.x4-b.x4;
  out.x5 = a.x5-b.x5;
  out.x6 = a.x6-b.x6;
  out.x7 = a.x7-b.x7;
  return out;
}
vector8d vector8dScale(double s,vector8d a){
  vector8d out;
  out.x0 = s*a.x0;
  out.x1 = s*a.x1;
  out.x2 = s*a.x2;
  out.x3 = s*a.x3;
  out.x4 = s*a.x4;
  out.x5 = s*a.x5;
  out.x6 = s*a.x6;
  out.x7 = s*a.x7;
  return out;
}
double vector8dDot(vector8d a, vector8d b){
  double out = 0;
  out += a.x0*b.x0;
  out += a.x1*b.x1;
  out += a.x2*b.x2;
  out += a.x3*b.x3;
  out += a.x4*b.x4;
  out += a.x5*b.x5;
  out += a.x6*b.x6;
  out += a.x7*b.x7;
  return out;
}
double vector8dLen(vector8d a){
  double out = 0;
  out += a.x0*a.x0;
  out += a.x1*a.x1;
  out += a.x2*a.x2;
  out += a.x3*a.x3;
  out += a.x4*a.x4;
  out += a.x5*a.x5;
  out += a.x6*a.x6;
  out += a.x7*a.x7;
  return sqrt(out);
}
vector8d vector8dNormalize(vector8d a){return vector8dScale(1/vector8dLen(a),a);}
double vector8dAngle(vector8d a, vector8d b){a = vector8dNormalize(a); b = vector8dNormalize(b);return acos(vector8dDot(a,b));}
void vector8dprint(vector8d v){
  printf("%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf",v.x0, v.x1, v.x2, v.x3, v.x4, v.x5, v.x6, v.x7);
}
 
vector9d vector9dAdd(vector9d a, vector9d b){
  vector9d out;
  out.x0 = a.x0+b.x0;
  out.x1 = a.x1+b.x1;
  out.x2 = a.x2+b.x2;
  out.x3 = a.x3+b.x3;
  out.x4 = a.x4+b.x4;
  out.x5 = a.x5+b.x5;
  out.x6 = a.x6+b.x6;
  out.x7 = a.x7+b.x7;
  out.x8 = a.x8+b.x8;
  return out;
}
vector9d vector9dSub(vector9d a, vector9d b){
  vector9d out;
  out.x0 = a.x0-b.x0;
  out.x1 = a.x1-b.x1;
  out.x2 = a.x2-b.x2;
  out.x3 = a.x3-b.x3;
  out.x4 = a.x4-b.x4;
  out.x5 = a.x5-b.x5;
  out.x6 = a.x6-b.x6;
  out.x7 = a.x7-b.x7;
  out.x8 = a.x8-b.x8;
  return out;
}
vector9d vector9dScale(double s,vector9d a){
  vector9d out;
  out.x0 = s*a.x0;
  out.x1 = s*a.x1;
  out.x2 = s*a.x2;
  out.x3 = s*a.x3;
  out.x4 = s*a.x4;
  out.x5 = s*a.x5;
  out.x6 = s*a.x6;
  out.x7 = s*a.x7;
  out.x8 = s*a.x8;
  return out;
}
double vector9dDot(vector9d a, vector9d b){
  double out = 0;
  out += a.x0*b.x0;
  out += a.x1*b.x1;
  out += a.x2*b.x2;
  out += a.x3*b.x3;
  out += a.x4*b.x4;
  out += a.x5*b.x5;
  out += a.x6*b.x6;
  out += a.x7*b.x7;
  out += a.x8*b.x8;
  return out;
}
double vector9dLen(vector9d a){
  double out = 0;
  out += a.x0*a.x0;
  out += a.x1*a.x1;
  out += a.x2*a.x2;
  out += a.x3*a.x3;
  out += a.x4*a.x4;
  out += a.x5*a.x5;
  out += a.x6*a.x6;
  out += a.x7*a.x7;
  out += a.x8*a.x8;
  return sqrt(out);
}
vector9d vector9dNormalize(vector9d a){return vector9dScale(1/vector9dLen(a),a);}
double vector9dAngle(vector9d a, vector9d b){a = vector9dNormalize(a); b = vector9dNormalize(b);return acos(vector9dDot(a,b));}
void vector9dprint(vector9d v){
  printf("%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf",v.x0, v.x1, v.x2, v.x3, v.x4, v.x5, v.x6, v.x7, v.x8);
}
 
vector10d vector10dAdd(vector10d a, vector10d b){
  vector10d out;
  out.x0 = a.x0+b.x0;
  out.x1 = a.x1+b.x1;
  out.x2 = a.x2+b.x2;
  out.x3 = a.x3+b.x3;
  out.x4 = a.x4+b.x4;
  out.x5 = a.x5+b.x5;
  out.x6 = a.x6+b.x6;
  out.x7 = a.x7+b.x7;
  out.x8 = a.x8+b.x8;
  out.x9 = a.x9+b.x9;
  return out;
}
vector10d vector10dSub(vector10d a, vector10d b){
  vector10d out;
  out.x0 = a.x0-b.x0;
  out.x1 = a.x1-b.x1;
  out.x2 = a.x2-b.x2;
  out.x3 = a.x3-b.x3;
  out.x4 = a.x4-b.x4;
  out.x5 = a.x5-b.x5;
  out.x6 = a.x6-b.x6;
  out.x7 = a.x7-b.x7;
  out.x8 = a.x8-b.x8;
  out.x9 = a.x9-b.x9;
  return out;
}
vector10d vector10dScale(double s,vector10d a){
  vector10d out;
  out.x0 = s*a.x0;
  out.x1 = s*a.x1;
  out.x2 = s*a.x2;
  out.x3 = s*a.x3;
  out.x4 = s*a.x4;
  out.x5 = s*a.x5;
  out.x6 = s*a.x6;
  out.x7 = s*a.x7;
  out.x8 = s*a.x8;
  out.x9 = s*a.x9;
  return out;
}
double vector10dDot(vector10d a, vector10d b){
  double out = 0;
  out += a.x0*b.x0;
  out += a.x1*b.x1;
  out += a.x2*b.x2;
  out += a.x3*b.x3;
  out += a.x4*b.x4;
  out += a.x5*b.x5;
  out += a.x6*b.x6;
  out += a.x7*b.x7;
  out += a.x8*b.x8;
  out += a.x9*b.x9;
  return out;
}
double vector10dLen(vector10d a){
  double out = 0;
  out += a.x0*a.x0;
  out += a.x1*a.x1;
  out += a.x2*a.x2;
  out += a.x3*a.x3;
  out += a.x4*a.x4;
  out += a.x5*a.x5;
  out += a.x6*a.x6;
  out += a.x7*a.x7;
  out += a.x8*a.x8;
  out += a.x9*a.x9;
  return sqrt(out);
}
vector10d vector10dNormalize(vector10d a){return vector10dScale(1/vector10dLen(a),a);}
double vector10dAngle(vector10d a, vector10d b){a = vector10dNormalize(a); b = vector10dNormalize(b);return acos(vector10dDot(a,b));}
void vector10dprint(vector10d v){
  printf("%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf",v.x0, v.x1, v.x2, v.x3, v.x4, v.x5, v.x6, v.x7, v.x8, v.x9);
}
 
vector2d matrix2x2dCol(matrix2x2d v, int col){
            return (vector2d){.x = v.data[0][col], .y = v.data[1][col]};
}
vector2d matrix2x2dRow(matrix2x2d v, int row){
            return (vector2d){.x = v.data[0][row], .y = v.data[1][row]};
}
matrix2x2d matrix2x2dAdd(matrix2x2d a, matrix2x2d b){    matrix2x2d out = {};
    for(int y = 0; y<2; y++){
        for(int x = 0;x<2; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix2x2d matrix2x2dSub(matrix2x2d a, matrix2x2d b){    matrix2x2d out = {};
    for(int y = 0; y<2; y++){
        for(int x = 0;x<2; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector2d matrix2x2dMltVec(matrix2x2d a, vector2d b){
  vector2d out = {vector2dDot(matrix2x2dRow(a, 0), b), vector2dDot(matrix2x2dRow(a, 1), b)};
  return out;
}
matrix2x2d matrix2x2dMlt(matrix2x2d a, matrix2x2d b){
    matrix2x2d out = {};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix2x2d matrix2x2dIdentity(){
  matrix2x2d out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  return out;
}
matrix2x2d matrix2x2dScale(double s, matrix2x2d a){    matrix2x2d out = {};
    for(int y = 0; y<2; y++){
        for(int x = 0;x<2; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix2x2d matrix2x2dTranspose(matrix2x2d a){    matrix2x2d out = {};
    for(int y = 0; y<2; y++){
        for(int x = 0;x<2; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector3d matrix3x3dCol(matrix3x3d v, int col){
            return (vector3d){.x = v.data[0][col], .y = v.data[1][col], .z = v.data[2][col]};
}
vector3d matrix3x3dRow(matrix3x3d v, int row){
            return (vector3d){.x = v.data[row][0], .y = v.data[row][1], .z = v.data[row][2]};
}
matrix3x3d matrix3x3dAdd(matrix3x3d a, matrix3x3d b){    matrix3x3d out = {};
    for(int y = 0; y<3; y++){
        for(int x = 0;x<3; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix3x3d matrix3x3dSub(matrix3x3d a, matrix3x3d b){    matrix3x3d out = {};
    for(int y = 0; y<3; y++){
        for(int x = 0;x<3; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector3d matrix3x3dMltVec(matrix3x3d a, vector3d b){
  vector3d out = {vector3dDot(matrix3x3dRow(a, 0), b), vector3dDot(matrix3x3dRow(a, 1), b),vector3dDot(matrix3x3dRow(a, 2), b)};  return out;
}
matrix3x3d matrix3x3dMlt(matrix3x3d a, matrix3x3d b){
    matrix3x3d out = {};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix3x3d matrix3x3dIdentity(){
  matrix3x3d out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  return out;
}
matrix3x3d matrix3x3dScale(double s, matrix3x3d a){    matrix3x3d out = {};
    for(int y = 0; y<3; y++){
        for(int x = 0;x<3; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix3x3d matrix3x3dTranspose(matrix3x3d a){    matrix3x3d out = {};
    for(int y = 0; y<3; y++){
        for(int x = 0;x<3; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector4d matrix4x4dCol(matrix4x4d v, int col){
            return (vector4d){.w = v.data[0][col],.x = v.data[1][col], .y = v.data[2][col], .z = v.data[3][col]};
}
vector4d matrix4x4dRow(matrix4x4d v, int row){
            return (vector4d){.w = v.data[row][0],.x = v.data[row][1], .y = v.data[row][2], .z = v.data[row][3]};
}
matrix4x4d matrix4x4dAdd(matrix4x4d a, matrix4x4d b){    matrix4x4d out = {};
    for(int y = 0; y<4; y++){
        for(int x = 0;x<4; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix4x4d matrix4x4dSub(matrix4x4d a, matrix4x4d b){    matrix4x4d out = {};
    for(int y = 0; y<4; y++){
        for(int x = 0;x<4; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector4d matrix4x4dMltVec(matrix4x4d a, vector4d b){
  vector4d out = {vector4dDot(matrix4x4dRow(a, 0), b), vector4dDot(matrix4x4dRow(a, 1), b),vector4dDot(matrix4x4dRow(a, 2), b), vector4dDot(matrix4x4dRow(a,3), b)};return out;
}
matrix4x4d matrix4x4dMlt(matrix4x4d a, matrix4x4d b){
    matrix4x4d out = {};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix4x4d matrix4x4dIdentity(){
  matrix4x4d out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  return out;
}
matrix4x4d matrix4x4dScale(double s, matrix4x4d a){    matrix4x4d out = {};
    for(int y = 0; y<4; y++){
        for(int x = 0;x<4; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix4x4d matrix4x4dTranspose(matrix4x4d a){    matrix4x4d out = {};
    for(int y = 0; y<4; y++){
        for(int x = 0;x<4; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector5d matrix5x5dCol(matrix5x5d v, int col){
   vector5d out = {};
  out.x0 = v.data[0][col];
  out.x1 = v.data[1][col];
  out.x2 = v.data[2][col];
  out.x3 = v.data[3][col];
  out.x4 = v.data[4][col];
   return out;
}
vector5d matrix5x5dRow(matrix5x5d v, int row){
   vector5d out = {};
  out.x0 = v.data[row][0];
  out.x1 = v.data[row][1];
  out.x2 = v.data[row][2];
  out.x3 = v.data[row][3];
  out.x4 = v.data[row][4];
   return out;
}
matrix5x5d matrix5x5dAdd(matrix5x5d a, matrix5x5d b){    matrix5x5d out = {};
    for(int y = 0; y<5; y++){
        for(int x = 0;x<5; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix5x5d matrix5x5dSub(matrix5x5d a, matrix5x5d b){    matrix5x5d out = {};
    for(int y = 0; y<5; y++){
        for(int x = 0;x<5; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector5d matrix5x5dMltVec(matrix5x5d a, vector5d b){
  vector5d out = {};
  out.x0 = vector5dDot(matrix5x5dRow(a, 0), b);  out.x1 = vector5dDot(matrix5x5dRow(a, 1), b);  out.x2 = vector5dDot(matrix5x5dRow(a, 2), b);  out.x3 = vector5dDot(matrix5x5dRow(a, 3), b);  out.x4 = vector5dDot(matrix5x5dRow(a, 4), b); 
  return out;
}
matrix5x5d matrix5x5dMlt(matrix5x5d a, matrix5x5d b){
    matrix5x5d out = {};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 5; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix5x5d matrix5x5dIdentity(){
  matrix5x5d out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  out.data[4][4] = 1;
  return out;
}
matrix5x5d matrix5x5dScale(double s, matrix5x5d a){    matrix5x5d out = {};
    for(int y = 0; y<5; y++){
        for(int x = 0;x<5; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix5x5d matrix5x5dTranspose(matrix5x5d a){    matrix5x5d out = {};
    for(int y = 0; y<5; y++){
        for(int x = 0;x<5; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector6d matrix6x6dCol(matrix6x6d v, int col){
   vector6d out = {};
  out.x0 = v.data[0][col];
  out.x1 = v.data[1][col];
  out.x2 = v.data[2][col];
  out.x3 = v.data[3][col];
  out.x4 = v.data[4][col];
  out.x5 = v.data[5][col];
   return out;
}
vector6d matrix6x6dRow(matrix6x6d v, int row){
   vector6d out = {};
  out.x0 = v.data[row][0];
  out.x1 = v.data[row][1];
  out.x2 = v.data[row][2];
  out.x3 = v.data[row][3];
  out.x4 = v.data[row][4];
  out.x5 = v.data[row][5];
   return out;
}
matrix6x6d matrix6x6dAdd(matrix6x6d a, matrix6x6d b){    matrix6x6d out = {};
    for(int y = 0; y<6; y++){
        for(int x = 0;x<6; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix6x6d matrix6x6dSub(matrix6x6d a, matrix6x6d b){    matrix6x6d out = {};
    for(int y = 0; y<6; y++){
        for(int x = 0;x<6; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector6d matrix6x6dMltVec(matrix6x6d a, vector6d b){
  vector6d out = {};
  out.x0 = vector6dDot(matrix6x6dRow(a, 0), b);  out.x1 = vector6dDot(matrix6x6dRow(a, 1), b);  out.x2 = vector6dDot(matrix6x6dRow(a, 2), b);  out.x3 = vector6dDot(matrix6x6dRow(a, 3), b);  out.x4 = vector6dDot(matrix6x6dRow(a, 4), b);  out.x5 = vector6dDot(matrix6x6dRow(a, 5), b); 
  return out;
}
matrix6x6d matrix6x6dMlt(matrix6x6d a, matrix6x6d b){
    matrix6x6d out = {};
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 6; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix6x6d matrix6x6dIdentity(){
  matrix6x6d out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  out.data[4][4] = 1;
  out.data[5][5] = 1;
  return out;
}
matrix6x6d matrix6x6dScale(double s, matrix6x6d a){    matrix6x6d out = {};
    for(int y = 0; y<6; y++){
        for(int x = 0;x<6; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix6x6d matrix6x6dTranspose(matrix6x6d a){    matrix6x6d out = {};
    for(int y = 0; y<6; y++){
        for(int x = 0;x<6; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector7d matrix7x7dCol(matrix7x7d v, int col){
   vector7d out = {};
  out.x0 = v.data[0][col];
  out.x1 = v.data[1][col];
  out.x2 = v.data[2][col];
  out.x3 = v.data[3][col];
  out.x4 = v.data[4][col];
  out.x5 = v.data[5][col];
  out.x6 = v.data[6][col];
   return out;
}
vector7d matrix7x7dRow(matrix7x7d v, int row){
   vector7d out = {};
  out.x0 = v.data[row][0];
  out.x1 = v.data[row][1];
  out.x2 = v.data[row][2];
  out.x3 = v.data[row][3];
  out.x4 = v.data[row][4];
  out.x5 = v.data[row][5];
  out.x6 = v.data[row][6];
   return out;
}
matrix7x7d matrix7x7dAdd(matrix7x7d a, matrix7x7d b){    matrix7x7d out = {};
    for(int y = 0; y<7; y++){
        for(int x = 0;x<7; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix7x7d matrix7x7dSub(matrix7x7d a, matrix7x7d b){    matrix7x7d out = {};
    for(int y = 0; y<7; y++){
        for(int x = 0;x<7; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector7d matrix7x7dMltVec(matrix7x7d a, vector7d b){
  vector7d out = {};
  out.x0 = vector7dDot(matrix7x7dRow(a, 0), b);  out.x1 = vector7dDot(matrix7x7dRow(a, 1), b);  out.x2 = vector7dDot(matrix7x7dRow(a, 2), b);  out.x3 = vector7dDot(matrix7x7dRow(a, 3), b);  out.x4 = vector7dDot(matrix7x7dRow(a, 4), b);  out.x5 = vector7dDot(matrix7x7dRow(a, 5), b);  out.x6 = vector7dDot(matrix7x7dRow(a, 6), b); 
  return out;
}
matrix7x7d matrix7x7dMlt(matrix7x7d a, matrix7x7d b){
    matrix7x7d out = {};
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 7; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix7x7d matrix7x7dIdentity(){
  matrix7x7d out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  out.data[4][4] = 1;
  out.data[5][5] = 1;
  out.data[6][6] = 1;
  return out;
}
matrix7x7d matrix7x7dScale(double s, matrix7x7d a){    matrix7x7d out = {};
    for(int y = 0; y<7; y++){
        for(int x = 0;x<7; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix7x7d matrix7x7dTranspose(matrix7x7d a){    matrix7x7d out = {};
    for(int y = 0; y<7; y++){
        for(int x = 0;x<7; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector8d matrix8x8dCol(matrix8x8d v, int col){
   vector8d out = {};
  out.x0 = v.data[0][col];
  out.x1 = v.data[1][col];
  out.x2 = v.data[2][col];
  out.x3 = v.data[3][col];
  out.x4 = v.data[4][col];
  out.x5 = v.data[5][col];
  out.x6 = v.data[6][col];
  out.x7 = v.data[7][col];
   return out;
}
vector8d matrix8x8dRow(matrix8x8d v, int row){
   vector8d out = {};
  out.x0 = v.data[row][0];
  out.x1 = v.data[row][1];
  out.x2 = v.data[row][2];
  out.x3 = v.data[row][3];
  out.x4 = v.data[row][4];
  out.x5 = v.data[row][5];
  out.x6 = v.data[row][6];
  out.x7 = v.data[row][7];
   return out;
}
matrix8x8d matrix8x8dAdd(matrix8x8d a, matrix8x8d b){    matrix8x8d out = {};
    for(int y = 0; y<8; y++){
        for(int x = 0;x<8; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix8x8d matrix8x8dSub(matrix8x8d a, matrix8x8d b){    matrix8x8d out = {};
    for(int y = 0; y<8; y++){
        for(int x = 0;x<8; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector8d matrix8x8dMltVec(matrix8x8d a, vector8d b){
  vector8d out = {};
  out.x0 = vector8dDot(matrix8x8dRow(a, 0), b);  out.x1 = vector8dDot(matrix8x8dRow(a, 1), b);  out.x2 = vector8dDot(matrix8x8dRow(a, 2), b);  out.x3 = vector8dDot(matrix8x8dRow(a, 3), b);  out.x4 = vector8dDot(matrix8x8dRow(a, 4), b);  out.x5 = vector8dDot(matrix8x8dRow(a, 5), b);  out.x6 = vector8dDot(matrix8x8dRow(a, 6), b);  out.x7 = vector8dDot(matrix8x8dRow(a, 7), b); 
  return out;
}
matrix8x8d matrix8x8dMlt(matrix8x8d a, matrix8x8d b){
    matrix8x8d out = {};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 8; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix8x8d matrix8x8dIdentity(){
  matrix8x8d out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  out.data[4][4] = 1;
  out.data[5][5] = 1;
  out.data[6][6] = 1;
  out.data[7][7] = 1;
  return out;
}
matrix8x8d matrix8x8dScale(double s, matrix8x8d a){    matrix8x8d out = {};
    for(int y = 0; y<8; y++){
        for(int x = 0;x<8; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix8x8d matrix8x8dTranspose(matrix8x8d a){    matrix8x8d out = {};
    for(int y = 0; y<8; y++){
        for(int x = 0;x<8; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector9d matrix9x9dCol(matrix9x9d v, int col){
   vector9d out = {};
  out.x0 = v.data[0][col];
  out.x1 = v.data[1][col];
  out.x2 = v.data[2][col];
  out.x3 = v.data[3][col];
  out.x4 = v.data[4][col];
  out.x5 = v.data[5][col];
  out.x6 = v.data[6][col];
  out.x7 = v.data[7][col];
  out.x8 = v.data[8][col];
   return out;
}
vector9d matrix9x9dRow(matrix9x9d v, int row){
   vector9d out = {};
  out.x0 = v.data[row][0];
  out.x1 = v.data[row][1];
  out.x2 = v.data[row][2];
  out.x3 = v.data[row][3];
  out.x4 = v.data[row][4];
  out.x5 = v.data[row][5];
  out.x6 = v.data[row][6];
  out.x7 = v.data[row][7];
  out.x8 = v.data[row][8];
   return out;
}
matrix9x9d matrix9x9dAdd(matrix9x9d a, matrix9x9d b){    matrix9x9d out = {};
    for(int y = 0; y<9; y++){
        for(int x = 0;x<9; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix9x9d matrix9x9dSub(matrix9x9d a, matrix9x9d b){    matrix9x9d out = {};
    for(int y = 0; y<9; y++){
        for(int x = 0;x<9; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector9d matrix9x9dMltVec(matrix9x9d a, vector9d b){
  vector9d out = {};
  out.x0 = vector9dDot(matrix9x9dRow(a, 0), b);  out.x1 = vector9dDot(matrix9x9dRow(a, 1), b);  out.x2 = vector9dDot(matrix9x9dRow(a, 2), b);  out.x3 = vector9dDot(matrix9x9dRow(a, 3), b);  out.x4 = vector9dDot(matrix9x9dRow(a, 4), b);  out.x5 = vector9dDot(matrix9x9dRow(a, 5), b);  out.x6 = vector9dDot(matrix9x9dRow(a, 6), b);  out.x7 = vector9dDot(matrix9x9dRow(a, 7), b);  out.x8 = vector9dDot(matrix9x9dRow(a, 8), b); 
  return out;
}
matrix9x9d matrix9x9dMlt(matrix9x9d a, matrix9x9d b){
    matrix9x9d out = {};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 9; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix9x9d matrix9x9dIdentity(){
  matrix9x9d out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  out.data[4][4] = 1;
  out.data[5][5] = 1;
  out.data[6][6] = 1;
  out.data[7][7] = 1;
  out.data[8][8] = 1;
  return out;
}
matrix9x9d matrix9x9dScale(double s, matrix9x9d a){    matrix9x9d out = {};
    for(int y = 0; y<9; y++){
        for(int x = 0;x<9; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix9x9d matrix9x9dTranspose(matrix9x9d a){    matrix9x9d out = {};
    for(int y = 0; y<9; y++){
        for(int x = 0;x<9; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector10d matrix10x10dCol(matrix10x10d v, int col){
   vector10d out = {};
  out.x0 = v.data[0][col];
  out.x1 = v.data[1][col];
  out.x2 = v.data[2][col];
  out.x3 = v.data[3][col];
  out.x4 = v.data[4][col];
  out.x5 = v.data[5][col];
  out.x6 = v.data[6][col];
  out.x7 = v.data[7][col];
  out.x8 = v.data[8][col];
  out.x9 = v.data[9][col];
   return out;
}
vector10d matrix10x10dRow(matrix10x10d v, int row){
   vector10d out = {};
  out.x0 = v.data[row][0];
  out.x1 = v.data[row][1];
  out.x2 = v.data[row][2];
  out.x3 = v.data[row][3];
  out.x4 = v.data[row][4];
  out.x5 = v.data[row][5];
  out.x6 = v.data[row][6];
  out.x7 = v.data[row][7];
  out.x8 = v.data[row][8];
  out.x9 = v.data[row][9];
   return out;
}
matrix10x10d matrix10x10dAdd(matrix10x10d a, matrix10x10d b){    matrix10x10d out = {};
    for(int y = 0; y<10; y++){
        for(int x = 0;x<10; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix10x10d matrix10x10dSub(matrix10x10d a, matrix10x10d b){    matrix10x10d out = {};
    for(int y = 0; y<10; y++){
        for(int x = 0;x<10; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector10d matrix10x10dMltVec(matrix10x10d a, vector10d b){
  vector10d out = {};
  out.x0 = vector10dDot(matrix10x10dRow(a, 0), b);  out.x1 = vector10dDot(matrix10x10dRow(a, 1), b);  out.x2 = vector10dDot(matrix10x10dRow(a, 2), b);  out.x3 = vector10dDot(matrix10x10dRow(a, 3), b);  out.x4 = vector10dDot(matrix10x10dRow(a, 4), b);  out.x5 = vector10dDot(matrix10x10dRow(a, 5), b);  out.x6 = vector10dDot(matrix10x10dRow(a, 6), b);  out.x7 = vector10dDot(matrix10x10dRow(a, 7), b);  out.x8 = vector10dDot(matrix10x10dRow(a, 8), b);  out.x9 = vector10dDot(matrix10x10dRow(a, 9), b); 
  return out;
}
matrix10x10d matrix10x10dMlt(matrix10x10d a, matrix10x10d b){
    matrix10x10d out = {};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 10; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix10x10d matrix10x10dIdentity(){
  matrix10x10d out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  out.data[4][4] = 1;
  out.data[5][5] = 1;
  out.data[6][6] = 1;
  out.data[7][7] = 1;
  out.data[8][8] = 1;
  out.data[9][9] = 1;
  return out;
}
matrix10x10d matrix10x10dScale(double s, matrix10x10d a){    matrix10x10d out = {};
    for(int y = 0; y<10; y++){
        for(int x = 0;x<10; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix10x10d matrix10x10dTranspose(matrix10x10d a){    matrix10x10d out = {};
    for(int y = 0; y<10; y++){
        for(int x = 0;x<10; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector2f vector2fAdd(vector2f a, vector2f b){
  return (vector2f){a.x +b.x, a.y+b.y};
}
vector2f vector2fSub(vector2f a, vector2f b){
  return (vector2f){a.x-b.x, a.y-b.y};
}
vector2f vector2fScale(float s, vector2f a){
  return (vector2f){a.x*s, a.y*s};
}
float vector2fDot(vector2f a, vector2f b){
  return a.x*b.x+a.y*b.y;
}
float vector2fLen(vector2f a){
  return sqrtf(a.x*a.x+a.y*a.y);
}
vector2f vector2fNormalize(vector2f a){return vector2fScale(1/vector2fLen(a),a);}
float vector2fAngle(vector2f a, vector2f b){a = vector2fNormalize(a); b = vector2fNormalize(b);return acosf(vector2fDot(a,b));}
void vector2fprint(vector2f v){
  printf("%f, %f", v.x, v.y);
}
vector3f vector3fAdd(vector3f a, vector3f b){
  return (vector3f){a.x +b.x, a.y+b.y, a.z+b.z};
}
vector3f vector3fSub(vector3f a, vector3f b){
  return (vector3f){a.x-b.x, a.y-b.y, a.z-b.z};
}
vector3f vector3fScale(float s, vector3f a){
  return (vector3f){a.x*s, a.y*s, a.z*s};
}
float vector3fDot(vector3f a, vector3f b){
  return a.x*b.x+a.y*b.y+a.z*b.z;
}
float vector3fLen(vector3f a){
  return sqrtf(a.x*a.x+a.y*a.y+a.z*a.z);
}
vector3f vector3fNormalize(vector3f a){return vector3fScale(1/vector3fLen(a),a);}
float vector3fAngle(vector3f a, vector3f b){a = vector3fNormalize(a); b = vector3fNormalize(b);return acosf(vector3fDot(a,b));}
void vector3fprint(vector3f v){
  printf("%f, %f, %f", v.x, v.y, v.z);
}
vector4f vector4fAdd(vector4f a, vector4f b){
  return (vector4f){a.w+b.w,a.x+b.x, a.y+b.y, a.z+b.z};
}
vector4f vector4fSub(vector4f a, vector4f b){
  return (vector4f){a.w-b.w,a.x-b.x, a.y-b.y, a.z-b.z};
}
vector4f vector4fScale(float s, vector4f a){
  return (vector4f){a.w*s,a.x*s, a.y*s, a.z*s};
}
float vector4fDot(vector4f a, vector4f b){
  return a.w*b.w+a.x*b.x+a.y*b.y+a.z*b.z;
}
float vector4fLen(vector4f a){
  return sqrtf(a.w*a.w+a.x*a.x+a.y*a.y+a.z*a.z);
}
vector4f vector4fNormalize(vector4f a){return vector4fScale(1/vector4fLen(a),a);}
float vector4fAngle(vector4f a, vector4f b){a = vector4fNormalize(a); b = vector4fNormalize(b);return acosf(vector4fDot(a,b));}
void vector4fprint(vector4f v){
  printf("%f, %f, %f, %f", v.w,v.x, v.y, v.z);
}
vector5f vector5fAdd(vector5f a, vector5f b){
  vector5f out;
  out.x0 = a.x0+b.x0;
  out.x1 = a.x1+b.x1;
  out.x2 = a.x2+b.x2;
  out.x3 = a.x3+b.x3;
  out.x4 = a.x4+b.x4;
  return out;
}
vector5f vector5fSub(vector5f a, vector5f b){
  vector5f out;
  out.x0 = a.x0-b.x0;
  out.x1 = a.x1-b.x1;
  out.x2 = a.x2-b.x2;
  out.x3 = a.x3-b.x3;
  out.x4 = a.x4-b.x4;
  return out;
}
vector5f vector5fScale(float s,vector5f a){
  vector5f out;
  out.x0 = s*a.x0;
  out.x1 = s*a.x1;
  out.x2 = s*a.x2;
  out.x3 = s*a.x3;
  out.x4 = s*a.x4;
  return out;
}
float vector5fDot(vector5f a, vector5f b){
  float out = 0;
  out += a.x0*b.x0;
  out += a.x1*b.x1;
  out += a.x2*b.x2;
  out += a.x3*b.x3;
  out += a.x4*b.x4;
  return out;
}
float vector5fLen(vector5f a){
  float out = 0;
  out += a.x0*a.x0;
  out += a.x1*a.x1;
  out += a.x2*a.x2;
  out += a.x3*a.x3;
  out += a.x4*a.x4;
  return sqrtf(out);
}
vector5f vector5fNormalize(vector5f a){return vector5fScale(1/vector5fLen(a),a);}
float vector5fAngle(vector5f a, vector5f b){a = vector5fNormalize(a); b = vector5fNormalize(b);return acosf(vector5fDot(a,b));}
void vector5fprint(vector5f v){
  printf("%f, %f, %f, %f, %f",v.x0, v.x1, v.x2, v.x3, v.x4);
}
 
vector6f vector6fAdd(vector6f a, vector6f b){
  vector6f out;
  out.x0 = a.x0+b.x0;
  out.x1 = a.x1+b.x1;
  out.x2 = a.x2+b.x2;
  out.x3 = a.x3+b.x3;
  out.x4 = a.x4+b.x4;
  out.x5 = a.x5+b.x5;
  return out;
}
vector6f vector6fSub(vector6f a, vector6f b){
  vector6f out;
  out.x0 = a.x0-b.x0;
  out.x1 = a.x1-b.x1;
  out.x2 = a.x2-b.x2;
  out.x3 = a.x3-b.x3;
  out.x4 = a.x4-b.x4;
  out.x5 = a.x5-b.x5;
  return out;
}
vector6f vector6fScale(float s,vector6f a){
  vector6f out;
  out.x0 = s*a.x0;
  out.x1 = s*a.x1;
  out.x2 = s*a.x2;
  out.x3 = s*a.x3;
  out.x4 = s*a.x4;
  out.x5 = s*a.x5;
  return out;
}
float vector6fDot(vector6f a, vector6f b){
  float out = 0;
  out += a.x0*b.x0;
  out += a.x1*b.x1;
  out += a.x2*b.x2;
  out += a.x3*b.x3;
  out += a.x4*b.x4;
  out += a.x5*b.x5;
  return out;
}
float vector6fLen(vector6f a){
  float out = 0;
  out += a.x0*a.x0;
  out += a.x1*a.x1;
  out += a.x2*a.x2;
  out += a.x3*a.x3;
  out += a.x4*a.x4;
  out += a.x5*a.x5;
  return sqrtf(out);
}
vector6f vector6fNormalize(vector6f a){return vector6fScale(1/vector6fLen(a),a);}
float vector6fAngle(vector6f a, vector6f b){a = vector6fNormalize(a); b = vector6fNormalize(b);return acosf(vector6fDot(a,b));}
void vector6fprint(vector6f v){
  printf("%f, %f, %f, %f, %f, %f",v.x0, v.x1, v.x2, v.x3, v.x4, v.x5);
}
 
vector7f vector7fAdd(vector7f a, vector7f b){
  vector7f out;
  out.x0 = a.x0+b.x0;
  out.x1 = a.x1+b.x1;
  out.x2 = a.x2+b.x2;
  out.x3 = a.x3+b.x3;
  out.x4 = a.x4+b.x4;
  out.x5 = a.x5+b.x5;
  out.x6 = a.x6+b.x6;
  return out;
}
vector7f vector7fSub(vector7f a, vector7f b){
  vector7f out;
  out.x0 = a.x0-b.x0;
  out.x1 = a.x1-b.x1;
  out.x2 = a.x2-b.x2;
  out.x3 = a.x3-b.x3;
  out.x4 = a.x4-b.x4;
  out.x5 = a.x5-b.x5;
  out.x6 = a.x6-b.x6;
  return out;
}
vector7f vector7fScale(float s,vector7f a){
  vector7f out;
  out.x0 = s*a.x0;
  out.x1 = s*a.x1;
  out.x2 = s*a.x2;
  out.x3 = s*a.x3;
  out.x4 = s*a.x4;
  out.x5 = s*a.x5;
  out.x6 = s*a.x6;
  return out;
}
float vector7fDot(vector7f a, vector7f b){
  float out = 0;
  out += a.x0*b.x0;
  out += a.x1*b.x1;
  out += a.x2*b.x2;
  out += a.x3*b.x3;
  out += a.x4*b.x4;
  out += a.x5*b.x5;
  out += a.x6*b.x6;
  return out;
}
float vector7fLen(vector7f a){
  float out = 0;
  out += a.x0*a.x0;
  out += a.x1*a.x1;
  out += a.x2*a.x2;
  out += a.x3*a.x3;
  out += a.x4*a.x4;
  out += a.x5*a.x5;
  out += a.x6*a.x6;
  return sqrtf(out);
}
vector7f vector7fNormalize(vector7f a){return vector7fScale(1/vector7fLen(a),a);}
float vector7fAngle(vector7f a, vector7f b){a = vector7fNormalize(a); b = vector7fNormalize(b);return acosf(vector7fDot(a,b));}
void vector7fprint(vector7f v){
  printf("%f, %f, %f, %f, %f, %f, %f",v.x0, v.x1, v.x2, v.x3, v.x4, v.x5, v.x6);
}
 
vector8f vector8fAdd(vector8f a, vector8f b){
  vector8f out;
  out.x0 = a.x0+b.x0;
  out.x1 = a.x1+b.x1;
  out.x2 = a.x2+b.x2;
  out.x3 = a.x3+b.x3;
  out.x4 = a.x4+b.x4;
  out.x5 = a.x5+b.x5;
  out.x6 = a.x6+b.x6;
  out.x7 = a.x7+b.x7;
  return out;
}
vector8f vector8fSub(vector8f a, vector8f b){
  vector8f out;
  out.x0 = a.x0-b.x0;
  out.x1 = a.x1-b.x1;
  out.x2 = a.x2-b.x2;
  out.x3 = a.x3-b.x3;
  out.x4 = a.x4-b.x4;
  out.x5 = a.x5-b.x5;
  out.x6 = a.x6-b.x6;
  out.x7 = a.x7-b.x7;
  return out;
}
vector8f vector8fScale(float s,vector8f a){
  vector8f out;
  out.x0 = s*a.x0;
  out.x1 = s*a.x1;
  out.x2 = s*a.x2;
  out.x3 = s*a.x3;
  out.x4 = s*a.x4;
  out.x5 = s*a.x5;
  out.x6 = s*a.x6;
  out.x7 = s*a.x7;
  return out;
}
float vector8fDot(vector8f a, vector8f b){
  float out = 0;
  out += a.x0*b.x0;
  out += a.x1*b.x1;
  out += a.x2*b.x2;
  out += a.x3*b.x3;
  out += a.x4*b.x4;
  out += a.x5*b.x5;
  out += a.x6*b.x6;
  out += a.x7*b.x7;
  return out;
}
float vector8fLen(vector8f a){
  float out = 0;
  out += a.x0*a.x0;
  out += a.x1*a.x1;
  out += a.x2*a.x2;
  out += a.x3*a.x3;
  out += a.x4*a.x4;
  out += a.x5*a.x5;
  out += a.x6*a.x6;
  out += a.x7*a.x7;
  return sqrtf(out);
}
vector8f vector8fNormalize(vector8f a){return vector8fScale(1/vector8fLen(a),a);}
float vector8fAngle(vector8f a, vector8f b){a = vector8fNormalize(a); b = vector8fNormalize(b);return acosf(vector8fDot(a,b));}
void vector8fprint(vector8f v){
  printf("%f, %f, %f, %f, %f, %f, %f, %f",v.x0, v.x1, v.x2, v.x3, v.x4, v.x5, v.x6, v.x7);
}
 
vector9f vector9fAdd(vector9f a, vector9f b){
  vector9f out;
  out.x0 = a.x0+b.x0;
  out.x1 = a.x1+b.x1;
  out.x2 = a.x2+b.x2;
  out.x3 = a.x3+b.x3;
  out.x4 = a.x4+b.x4;
  out.x5 = a.x5+b.x5;
  out.x6 = a.x6+b.x6;
  out.x7 = a.x7+b.x7;
  out.x8 = a.x8+b.x8;
  return out;
}
vector9f vector9fSub(vector9f a, vector9f b){
  vector9f out;
  out.x0 = a.x0-b.x0;
  out.x1 = a.x1-b.x1;
  out.x2 = a.x2-b.x2;
  out.x3 = a.x3-b.x3;
  out.x4 = a.x4-b.x4;
  out.x5 = a.x5-b.x5;
  out.x6 = a.x6-b.x6;
  out.x7 = a.x7-b.x7;
  out.x8 = a.x8-b.x8;
  return out;
}
vector9f vector9fScale(float s,vector9f a){
  vector9f out;
  out.x0 = s*a.x0;
  out.x1 = s*a.x1;
  out.x2 = s*a.x2;
  out.x3 = s*a.x3;
  out.x4 = s*a.x4;
  out.x5 = s*a.x5;
  out.x6 = s*a.x6;
  out.x7 = s*a.x7;
  out.x8 = s*a.x8;
  return out;
}
float vector9fDot(vector9f a, vector9f b){
  float out = 0;
  out += a.x0*b.x0;
  out += a.x1*b.x1;
  out += a.x2*b.x2;
  out += a.x3*b.x3;
  out += a.x4*b.x4;
  out += a.x5*b.x5;
  out += a.x6*b.x6;
  out += a.x7*b.x7;
  out += a.x8*b.x8;
  return out;
}
float vector9fLen(vector9f a){
  float out = 0;
  out += a.x0*a.x0;
  out += a.x1*a.x1;
  out += a.x2*a.x2;
  out += a.x3*a.x3;
  out += a.x4*a.x4;
  out += a.x5*a.x5;
  out += a.x6*a.x6;
  out += a.x7*a.x7;
  out += a.x8*a.x8;
  return sqrtf(out);
}
vector9f vector9fNormalize(vector9f a){return vector9fScale(1/vector9fLen(a),a);}
float vector9fAngle(vector9f a, vector9f b){a = vector9fNormalize(a); b = vector9fNormalize(b);return acosf(vector9fDot(a,b));}
void vector9fprint(vector9f v){
  printf("%f, %f, %f, %f, %f, %f, %f, %f, %f",v.x0, v.x1, v.x2, v.x3, v.x4, v.x5, v.x6, v.x7, v.x8);
}
 
vector10f vector10fAdd(vector10f a, vector10f b){
  vector10f out;
  out.x0 = a.x0+b.x0;
  out.x1 = a.x1+b.x1;
  out.x2 = a.x2+b.x2;
  out.x3 = a.x3+b.x3;
  out.x4 = a.x4+b.x4;
  out.x5 = a.x5+b.x5;
  out.x6 = a.x6+b.x6;
  out.x7 = a.x7+b.x7;
  out.x8 = a.x8+b.x8;
  out.x9 = a.x9+b.x9;
  return out;
}
vector10f vector10fSub(vector10f a, vector10f b){
  vector10f out;
  out.x0 = a.x0-b.x0;
  out.x1 = a.x1-b.x1;
  out.x2 = a.x2-b.x2;
  out.x3 = a.x3-b.x3;
  out.x4 = a.x4-b.x4;
  out.x5 = a.x5-b.x5;
  out.x6 = a.x6-b.x6;
  out.x7 = a.x7-b.x7;
  out.x8 = a.x8-b.x8;
  out.x9 = a.x9-b.x9;
  return out;
}
vector10f vector10fScale(float s,vector10f a){
  vector10f out;
  out.x0 = s*a.x0;
  out.x1 = s*a.x1;
  out.x2 = s*a.x2;
  out.x3 = s*a.x3;
  out.x4 = s*a.x4;
  out.x5 = s*a.x5;
  out.x6 = s*a.x6;
  out.x7 = s*a.x7;
  out.x8 = s*a.x8;
  out.x9 = s*a.x9;
  return out;
}
float vector10fDot(vector10f a, vector10f b){
  float out = 0;
  out += a.x0*b.x0;
  out += a.x1*b.x1;
  out += a.x2*b.x2;
  out += a.x3*b.x3;
  out += a.x4*b.x4;
  out += a.x5*b.x5;
  out += a.x6*b.x6;
  out += a.x7*b.x7;
  out += a.x8*b.x8;
  out += a.x9*b.x9;
  return out;
}
float vector10fLen(vector10f a){
  float out = 0;
  out += a.x0*a.x0;
  out += a.x1*a.x1;
  out += a.x2*a.x2;
  out += a.x3*a.x3;
  out += a.x4*a.x4;
  out += a.x5*a.x5;
  out += a.x6*a.x6;
  out += a.x7*a.x7;
  out += a.x8*a.x8;
  out += a.x9*a.x9;
  return sqrtf(out);
}
vector10f vector10fNormalize(vector10f a){return vector10fScale(1/vector10fLen(a),a);}
float vector10fAngle(vector10f a, vector10f b){a = vector10fNormalize(a); b = vector10fNormalize(b);return acosf(vector10fDot(a,b));}
void vector10fprint(vector10f v){
  printf("%f, %f, %f, %f, %f, %f, %f, %f, %f, %f",v.x0, v.x1, v.x2, v.x3, v.x4, v.x5, v.x6, v.x7, v.x8, v.x9);
}
 
vector2f matrix2x2fCol(matrix2x2f v, int col){
            return (vector2f){.x = v.data[0][col], .y = v.data[1][col]};
}
vector2f matrix2x2fRow(matrix2x2f v, int row){
            return (vector2f){.x = v.data[0][row], .y = v.data[1][row]};
}
matrix2x2f matrix2x2fAdd(matrix2x2f a, matrix2x2f b){    matrix2x2f out = {};
    for(int y = 0; y<2; y++){
        for(int x = 0;x<2; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix2x2f matrix2x2fSub(matrix2x2f a, matrix2x2f b){    matrix2x2f out = {};
    for(int y = 0; y<2; y++){
        for(int x = 0;x<2; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector2f matrix2x2fMltVec(matrix2x2f a, vector2f b){
  vector2f out = {vector2fDot(matrix2x2fRow(a, 0), b), vector2fDot(matrix2x2fRow(a, 1), b)};
  return out;
}
matrix2x2f matrix2x2fMlt(matrix2x2f a, matrix2x2f b){
    matrix2x2f out = {};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix2x2f matrix2x2fIdentity(){
  matrix2x2f out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  return out;
}
matrix2x2f matrix2x2fScale(float s, matrix2x2f a){    matrix2x2f out = {};
    for(int y = 0; y<2; y++){
        for(int x = 0;x<2; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix2x2f matrix2x2fTranspose(matrix2x2f a){    matrix2x2f out = {};
    for(int y = 0; y<2; y++){
        for(int x = 0;x<2; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector3f matrix3x3fCol(matrix3x3f v, int col){
            return (vector3f){.x = v.data[0][col], .y = v.data[1][col], .z = v.data[2][col]};
}
vector3f matrix3x3fRow(matrix3x3f v, int row){
            return (vector3f){.x = v.data[row][0], .y = v.data[row][1], .z = v.data[row][2]};
}
matrix3x3f matrix3x3fAdd(matrix3x3f a, matrix3x3f b){    matrix3x3f out = {};
    for(int y = 0; y<3; y++){
        for(int x = 0;x<3; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix3x3f matrix3x3fSub(matrix3x3f a, matrix3x3f b){    matrix3x3f out = {};
    for(int y = 0; y<3; y++){
        for(int x = 0;x<3; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector3f matrix3x3fMltVec(matrix3x3f a, vector3f b){
  vector3f out = {vector3fDot(matrix3x3fRow(a, 0), b), vector3fDot(matrix3x3fRow(a, 1), b),vector3fDot(matrix3x3fRow(a, 2), b)};  return out;
}
matrix3x3f matrix3x3fMlt(matrix3x3f a, matrix3x3f b){
    matrix3x3f out = {};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix3x3f matrix3x3fIdentity(){
  matrix3x3f out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  return out;
}
matrix3x3f matrix3x3fScale(float s, matrix3x3f a){    matrix3x3f out = {};
    for(int y = 0; y<3; y++){
        for(int x = 0;x<3; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix3x3f matrix3x3fTranspose(matrix3x3f a){    matrix3x3f out = {};
    for(int y = 0; y<3; y++){
        for(int x = 0;x<3; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector4f matrix4x4fCol(matrix4x4f v, int col){
            return (vector4f){.w = v.data[0][col],.x = v.data[1][col], .y = v.data[2][col], .z = v.data[3][col]};
}
vector4f matrix4x4fRow(matrix4x4f v, int row){
            return (vector4f){.w = v.data[row][0],.x = v.data[row][1], .y = v.data[row][2], .z = v.data[row][3]};
}
matrix4x4f matrix4x4fAdd(matrix4x4f a, matrix4x4f b){    matrix4x4f out = {};
    for(int y = 0; y<4; y++){
        for(int x = 0;x<4; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix4x4f matrix4x4fSub(matrix4x4f a, matrix4x4f b){    matrix4x4f out = {};
    for(int y = 0; y<4; y++){
        for(int x = 0;x<4; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector4f matrix4x4fMltVec(matrix4x4f a, vector4f b){
  vector4f out = {vector4fDot(matrix4x4fRow(a, 0), b), vector4fDot(matrix4x4fRow(a, 1), b),vector4fDot(matrix4x4fRow(a, 2), b), vector4fDot(matrix4x4fRow(a,3), b)};return out;
}
matrix4x4f matrix4x4fMlt(matrix4x4f a, matrix4x4f b){
    matrix4x4f out = {};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix4x4f matrix4x4fIdentity(){
  matrix4x4f out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  return out;
}
matrix4x4f matrix4x4fScale(float s, matrix4x4f a){    matrix4x4f out = {};
    for(int y = 0; y<4; y++){
        for(int x = 0;x<4; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix4x4f matrix4x4fTranspose(matrix4x4f a){    matrix4x4f out = {};
    for(int y = 0; y<4; y++){
        for(int x = 0;x<4; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector5f matrix5x5fCol(matrix5x5f v, int col){
   vector5f out = {};
  out.x0 = v.data[0][col];
  out.x1 = v.data[1][col];
  out.x2 = v.data[2][col];
  out.x3 = v.data[3][col];
  out.x4 = v.data[4][col];
   return out;
}
vector5f matrix5x5fRow(matrix5x5f v, int row){
   vector5f out = {};
  out.x0 = v.data[row][0];
  out.x1 = v.data[row][1];
  out.x2 = v.data[row][2];
  out.x3 = v.data[row][3];
  out.x4 = v.data[row][4];
   return out;
}
matrix5x5f matrix5x5fAdd(matrix5x5f a, matrix5x5f b){    matrix5x5f out = {};
    for(int y = 0; y<5; y++){
        for(int x = 0;x<5; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix5x5f matrix5x5fSub(matrix5x5f a, matrix5x5f b){    matrix5x5f out = {};
    for(int y = 0; y<5; y++){
        for(int x = 0;x<5; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector5f matrix5x5fMltVec(matrix5x5f a, vector5f b){
  vector5f out = {};
  out.x0 = vector5fDot(matrix5x5fRow(a, 0), b);  out.x1 = vector5fDot(matrix5x5fRow(a, 1), b);  out.x2 = vector5fDot(matrix5x5fRow(a, 2), b);  out.x3 = vector5fDot(matrix5x5fRow(a, 3), b);  out.x4 = vector5fDot(matrix5x5fRow(a, 4), b); 
  return out;
}
matrix5x5f matrix5x5fMlt(matrix5x5f a, matrix5x5f b){
    matrix5x5f out = {};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 5; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix5x5f matrix5x5fIdentity(){
  matrix5x5f out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  out.data[4][4] = 1;
  return out;
}
matrix5x5f matrix5x5fScale(float s, matrix5x5f a){    matrix5x5f out = {};
    for(int y = 0; y<5; y++){
        for(int x = 0;x<5; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix5x5f matrix5x5fTranspose(matrix5x5f a){    matrix5x5f out = {};
    for(int y = 0; y<5; y++){
        for(int x = 0;x<5; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector6f matrix6x6fCol(matrix6x6f v, int col){
   vector6f out = {};
  out.x0 = v.data[0][col];
  out.x1 = v.data[1][col];
  out.x2 = v.data[2][col];
  out.x3 = v.data[3][col];
  out.x4 = v.data[4][col];
  out.x5 = v.data[5][col];
   return out;
}
vector6f matrix6x6fRow(matrix6x6f v, int row){
   vector6f out = {};
  out.x0 = v.data[row][0];
  out.x1 = v.data[row][1];
  out.x2 = v.data[row][2];
  out.x3 = v.data[row][3];
  out.x4 = v.data[row][4];
  out.x5 = v.data[row][5];
   return out;
}
matrix6x6f matrix6x6fAdd(matrix6x6f a, matrix6x6f b){    matrix6x6f out = {};
    for(int y = 0; y<6; y++){
        for(int x = 0;x<6; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix6x6f matrix6x6fSub(matrix6x6f a, matrix6x6f b){    matrix6x6f out = {};
    for(int y = 0; y<6; y++){
        for(int x = 0;x<6; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector6f matrix6x6fMltVec(matrix6x6f a, vector6f b){
  vector6f out = {};
  out.x0 = vector6fDot(matrix6x6fRow(a, 0), b);  out.x1 = vector6fDot(matrix6x6fRow(a, 1), b);  out.x2 = vector6fDot(matrix6x6fRow(a, 2), b);  out.x3 = vector6fDot(matrix6x6fRow(a, 3), b);  out.x4 = vector6fDot(matrix6x6fRow(a, 4), b);  out.x5 = vector6fDot(matrix6x6fRow(a, 5), b); 
  return out;
}
matrix6x6f matrix6x6fMlt(matrix6x6f a, matrix6x6f b){
    matrix6x6f out = {};
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 6; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix6x6f matrix6x6fIdentity(){
  matrix6x6f out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  out.data[4][4] = 1;
  out.data[5][5] = 1;
  return out;
}
matrix6x6f matrix6x6fScale(float s, matrix6x6f a){    matrix6x6f out = {};
    for(int y = 0; y<6; y++){
        for(int x = 0;x<6; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix6x6f matrix6x6fTranspose(matrix6x6f a){    matrix6x6f out = {};
    for(int y = 0; y<6; y++){
        for(int x = 0;x<6; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector7f matrix7x7fCol(matrix7x7f v, int col){
   vector7f out = {};
  out.x0 = v.data[0][col];
  out.x1 = v.data[1][col];
  out.x2 = v.data[2][col];
  out.x3 = v.data[3][col];
  out.x4 = v.data[4][col];
  out.x5 = v.data[5][col];
  out.x6 = v.data[6][col];
   return out;
}
vector7f matrix7x7fRow(matrix7x7f v, int row){
   vector7f out = {};
  out.x0 = v.data[row][0];
  out.x1 = v.data[row][1];
  out.x2 = v.data[row][2];
  out.x3 = v.data[row][3];
  out.x4 = v.data[row][4];
  out.x5 = v.data[row][5];
  out.x6 = v.data[row][6];
   return out;
}
matrix7x7f matrix7x7fAdd(matrix7x7f a, matrix7x7f b){    matrix7x7f out = {};
    for(int y = 0; y<7; y++){
        for(int x = 0;x<7; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix7x7f matrix7x7fSub(matrix7x7f a, matrix7x7f b){    matrix7x7f out = {};
    for(int y = 0; y<7; y++){
        for(int x = 0;x<7; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector7f matrix7x7fMltVec(matrix7x7f a, vector7f b){
  vector7f out = {};
  out.x0 = vector7fDot(matrix7x7fRow(a, 0), b);  out.x1 = vector7fDot(matrix7x7fRow(a, 1), b);  out.x2 = vector7fDot(matrix7x7fRow(a, 2), b);  out.x3 = vector7fDot(matrix7x7fRow(a, 3), b);  out.x4 = vector7fDot(matrix7x7fRow(a, 4), b);  out.x5 = vector7fDot(matrix7x7fRow(a, 5), b);  out.x6 = vector7fDot(matrix7x7fRow(a, 6), b); 
  return out;
}
matrix7x7f matrix7x7fMlt(matrix7x7f a, matrix7x7f b){
    matrix7x7f out = {};
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 7; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix7x7f matrix7x7fIdentity(){
  matrix7x7f out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  out.data[4][4] = 1;
  out.data[5][5] = 1;
  out.data[6][6] = 1;
  return out;
}
matrix7x7f matrix7x7fScale(float s, matrix7x7f a){    matrix7x7f out = {};
    for(int y = 0; y<7; y++){
        for(int x = 0;x<7; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix7x7f matrix7x7fTranspose(matrix7x7f a){    matrix7x7f out = {};
    for(int y = 0; y<7; y++){
        for(int x = 0;x<7; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector8f matrix8x8fCol(matrix8x8f v, int col){
   vector8f out = {};
  out.x0 = v.data[0][col];
  out.x1 = v.data[1][col];
  out.x2 = v.data[2][col];
  out.x3 = v.data[3][col];
  out.x4 = v.data[4][col];
  out.x5 = v.data[5][col];
  out.x6 = v.data[6][col];
  out.x7 = v.data[7][col];
   return out;
}
vector8f matrix8x8fRow(matrix8x8f v, int row){
   vector8f out = {};
  out.x0 = v.data[row][0];
  out.x1 = v.data[row][1];
  out.x2 = v.data[row][2];
  out.x3 = v.data[row][3];
  out.x4 = v.data[row][4];
  out.x5 = v.data[row][5];
  out.x6 = v.data[row][6];
  out.x7 = v.data[row][7];
   return out;
}
matrix8x8f matrix8x8fAdd(matrix8x8f a, matrix8x8f b){    matrix8x8f out = {};
    for(int y = 0; y<8; y++){
        for(int x = 0;x<8; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix8x8f matrix8x8fSub(matrix8x8f a, matrix8x8f b){    matrix8x8f out = {};
    for(int y = 0; y<8; y++){
        for(int x = 0;x<8; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector8f matrix8x8fMltVec(matrix8x8f a, vector8f b){
  vector8f out = {};
  out.x0 = vector8fDot(matrix8x8fRow(a, 0), b);  out.x1 = vector8fDot(matrix8x8fRow(a, 1), b);  out.x2 = vector8fDot(matrix8x8fRow(a, 2), b);  out.x3 = vector8fDot(matrix8x8fRow(a, 3), b);  out.x4 = vector8fDot(matrix8x8fRow(a, 4), b);  out.x5 = vector8fDot(matrix8x8fRow(a, 5), b);  out.x6 = vector8fDot(matrix8x8fRow(a, 6), b);  out.x7 = vector8fDot(matrix8x8fRow(a, 7), b); 
  return out;
}
matrix8x8f matrix8x8fMlt(matrix8x8f a, matrix8x8f b){
    matrix8x8f out = {};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 8; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix8x8f matrix8x8fIdentity(){
  matrix8x8f out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  out.data[4][4] = 1;
  out.data[5][5] = 1;
  out.data[6][6] = 1;
  out.data[7][7] = 1;
  return out;
}
matrix8x8f matrix8x8fScale(float s, matrix8x8f a){    matrix8x8f out = {};
    for(int y = 0; y<8; y++){
        for(int x = 0;x<8; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix8x8f matrix8x8fTranspose(matrix8x8f a){    matrix8x8f out = {};
    for(int y = 0; y<8; y++){
        for(int x = 0;x<8; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector9f matrix9x9fCol(matrix9x9f v, int col){
   vector9f out = {};
  out.x0 = v.data[0][col];
  out.x1 = v.data[1][col];
  out.x2 = v.data[2][col];
  out.x3 = v.data[3][col];
  out.x4 = v.data[4][col];
  out.x5 = v.data[5][col];
  out.x6 = v.data[6][col];
  out.x7 = v.data[7][col];
  out.x8 = v.data[8][col];
   return out;
}
vector9f matrix9x9fRow(matrix9x9f v, int row){
   vector9f out = {};
  out.x0 = v.data[row][0];
  out.x1 = v.data[row][1];
  out.x2 = v.data[row][2];
  out.x3 = v.data[row][3];
  out.x4 = v.data[row][4];
  out.x5 = v.data[row][5];
  out.x6 = v.data[row][6];
  out.x7 = v.data[row][7];
  out.x8 = v.data[row][8];
   return out;
}
matrix9x9f matrix9x9fAdd(matrix9x9f a, matrix9x9f b){    matrix9x9f out = {};
    for(int y = 0; y<9; y++){
        for(int x = 0;x<9; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix9x9f matrix9x9fSub(matrix9x9f a, matrix9x9f b){    matrix9x9f out = {};
    for(int y = 0; y<9; y++){
        for(int x = 0;x<9; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector9f matrix9x9fMltVec(matrix9x9f a, vector9f b){
  vector9f out = {};
  out.x0 = vector9fDot(matrix9x9fRow(a, 0), b);  out.x1 = vector9fDot(matrix9x9fRow(a, 1), b);  out.x2 = vector9fDot(matrix9x9fRow(a, 2), b);  out.x3 = vector9fDot(matrix9x9fRow(a, 3), b);  out.x4 = vector9fDot(matrix9x9fRow(a, 4), b);  out.x5 = vector9fDot(matrix9x9fRow(a, 5), b);  out.x6 = vector9fDot(matrix9x9fRow(a, 6), b);  out.x7 = vector9fDot(matrix9x9fRow(a, 7), b);  out.x8 = vector9fDot(matrix9x9fRow(a, 8), b); 
  return out;
}
matrix9x9f matrix9x9fMlt(matrix9x9f a, matrix9x9f b){
    matrix9x9f out = {};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 9; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix9x9f matrix9x9fIdentity(){
  matrix9x9f out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  out.data[4][4] = 1;
  out.data[5][5] = 1;
  out.data[6][6] = 1;
  out.data[7][7] = 1;
  out.data[8][8] = 1;
  return out;
}
matrix9x9f matrix9x9fScale(float s, matrix9x9f a){    matrix9x9f out = {};
    for(int y = 0; y<9; y++){
        for(int x = 0;x<9; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix9x9f matrix9x9fTranspose(matrix9x9f a){    matrix9x9f out = {};
    for(int y = 0; y<9; y++){
        for(int x = 0;x<9; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector10f matrix10x10fCol(matrix10x10f v, int col){
   vector10f out = {};
  out.x0 = v.data[0][col];
  out.x1 = v.data[1][col];
  out.x2 = v.data[2][col];
  out.x3 = v.data[3][col];
  out.x4 = v.data[4][col];
  out.x5 = v.data[5][col];
  out.x6 = v.data[6][col];
  out.x7 = v.data[7][col];
  out.x8 = v.data[8][col];
  out.x9 = v.data[9][col];
   return out;
}
vector10f matrix10x10fRow(matrix10x10f v, int row){
   vector10f out = {};
  out.x0 = v.data[row][0];
  out.x1 = v.data[row][1];
  out.x2 = v.data[row][2];
  out.x3 = v.data[row][3];
  out.x4 = v.data[row][4];
  out.x5 = v.data[row][5];
  out.x6 = v.data[row][6];
  out.x7 = v.data[row][7];
  out.x8 = v.data[row][8];
  out.x9 = v.data[row][9];
   return out;
}
matrix10x10f matrix10x10fAdd(matrix10x10f a, matrix10x10f b){    matrix10x10f out = {};
    for(int y = 0; y<10; y++){
        for(int x = 0;x<10; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix10x10f matrix10x10fSub(matrix10x10f a, matrix10x10f b){    matrix10x10f out = {};
    for(int y = 0; y<10; y++){
        for(int x = 0;x<10; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector10f matrix10x10fMltVec(matrix10x10f a, vector10f b){
  vector10f out = {};
  out.x0 = vector10fDot(matrix10x10fRow(a, 0), b);  out.x1 = vector10fDot(matrix10x10fRow(a, 1), b);  out.x2 = vector10fDot(matrix10x10fRow(a, 2), b);  out.x3 = vector10fDot(matrix10x10fRow(a, 3), b);  out.x4 = vector10fDot(matrix10x10fRow(a, 4), b);  out.x5 = vector10fDot(matrix10x10fRow(a, 5), b);  out.x6 = vector10fDot(matrix10x10fRow(a, 6), b);  out.x7 = vector10fDot(matrix10x10fRow(a, 7), b);  out.x8 = vector10fDot(matrix10x10fRow(a, 8), b);  out.x9 = vector10fDot(matrix10x10fRow(a, 9), b); 
  return out;
}
matrix10x10f matrix10x10fMlt(matrix10x10f a, matrix10x10f b){
    matrix10x10f out = {};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 10; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix10x10f matrix10x10fIdentity(){
  matrix10x10f out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  out.data[4][4] = 1;
  out.data[5][5] = 1;
  out.data[6][6] = 1;
  out.data[7][7] = 1;
  out.data[8][8] = 1;
  out.data[9][9] = 1;
  return out;
}
matrix10x10f matrix10x10fScale(float s, matrix10x10f a){    matrix10x10f out = {};
    for(int y = 0; y<10; y++){
        for(int x = 0;x<10; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix10x10f matrix10x10fTranspose(matrix10x10f a){    matrix10x10f out = {};
    for(int y = 0; y<10; y++){
        for(int x = 0;x<10; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector2i vector2iAdd(vector2i a, vector2i b){
  return (vector2i){a.x +b.x, a.y+b.y};
}
vector2i vector2iSub(vector2i a, vector2i b){
  return (vector2i){a.x-b.x, a.y-b.y};
}
vector2i vector2iScale(int s, vector2i a){
  return (vector2i){a.x*s, a.y*s};
}
int vector2iDot(vector2i a, vector2i b){
  return a.x*b.x+a.y*b.y;
}
int vector2iLen(vector2i a){
  return ssqrt(a.x*a.x+a.y*a.y);
}
vector2i vector2iNormalize(vector2i a){return vector2iScale(1/vector2iLen(a),a);}
int vector2iAngle(vector2i a, vector2i b){a = vector2iNormalize(a); b = vector2iNormalize(b);return acos(vector2iDot(a,b));}
void vector2iprint(vector2i v){
  printf("%d, %d", v.x, v.y);
}
vector3i vector3iAdd(vector3i a, vector3i b){
  return (vector3i){a.x +b.x, a.y+b.y, a.z+b.z};
}
vector3i vector3iSub(vector3i a, vector3i b){
  return (vector3i){a.x-b.x, a.y-b.y, a.z-b.z};
}
vector3i vector3iScale(int s, vector3i a){
  return (vector3i){a.x*s, a.y*s, a.z*s};
}
int vector3iDot(vector3i a, vector3i b){
  return a.x*b.x+a.y*b.y+a.z*b.z;
}
int vector3iLen(vector3i a){
  return ssqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}
vector3i vector3iNormalize(vector3i a){return vector3iScale(1/vector3iLen(a),a);}
int vector3iAngle(vector3i a, vector3i b){a = vector3iNormalize(a); b = vector3iNormalize(b);return acos(vector3iDot(a,b));}
void vector3iprint(vector3i v){
  printf("%d, %d, %d", v.x, v.y, v.z);
}
vector4i vector4iAdd(vector4i a, vector4i b){
  return (vector4i){a.w+b.w,a.x+b.x, a.y+b.y, a.z+b.z};
}
vector4i vector4iSub(vector4i a, vector4i b){
  return (vector4i){a.w-b.w,a.x-b.x, a.y-b.y, a.z-b.z};
}
vector4i vector4iScale(int s, vector4i a){
  return (vector4i){a.w*s,a.x*s, a.y*s, a.z*s};
}
int vector4iDot(vector4i a, vector4i b){
  return a.w*b.w+a.x*b.x+a.y*b.y+a.z*b.z;
}
int vector4iLen(vector4i a){
  return ssqrt(a.w*a.w+a.x*a.x+a.y*a.y+a.z*a.z);
}
vector4i vector4iNormalize(vector4i a){return vector4iScale(1/vector4iLen(a),a);}
int vector4iAngle(vector4i a, vector4i b){a = vector4iNormalize(a); b = vector4iNormalize(b);return acos(vector4iDot(a,b));}
void vector4iprint(vector4i v){
  printf("%d, %d, %d, %d", v.w,v.x, v.y, v.z);
}
vector5i vector5iAdd(vector5i a, vector5i b){
  vector5i out;
  out.x0 = a.x0+b.x0;
  out.x1 = a.x1+b.x1;
  out.x2 = a.x2+b.x2;
  out.x3 = a.x3+b.x3;
  out.x4 = a.x4+b.x4;
  return out;
}
vector5i vector5iSub(vector5i a, vector5i b){
  vector5i out;
  out.x0 = a.x0-b.x0;
  out.x1 = a.x1-b.x1;
  out.x2 = a.x2-b.x2;
  out.x3 = a.x3-b.x3;
  out.x4 = a.x4-b.x4;
  return out;
}
vector5i vector5iScale(int s,vector5i a){
  vector5i out;
  out.x0 = s*a.x0;
  out.x1 = s*a.x1;
  out.x2 = s*a.x2;
  out.x3 = s*a.x3;
  out.x4 = s*a.x4;
  return out;
}
int vector5iDot(vector5i a, vector5i b){
  int out = 0;
  out += a.x0*b.x0;
  out += a.x1*b.x1;
  out += a.x2*b.x2;
  out += a.x3*b.x3;
  out += a.x4*b.x4;
  return out;
}
int vector5iLen(vector5i a){
  int out = 0;
  out += a.x0*a.x0;
  out += a.x1*a.x1;
  out += a.x2*a.x2;
  out += a.x3*a.x3;
  out += a.x4*a.x4;
  return ssqrt(out);
}
vector5i vector5iNormalize(vector5i a){return vector5iScale(1/vector5iLen(a),a);}
int vector5iAngle(vector5i a, vector5i b){a = vector5iNormalize(a); b = vector5iNormalize(b);return acos(vector5iDot(a,b));}
void vector5iprint(vector5i v){
  printf("%d, %d, %d, %d, %d",v.x0, v.x1, v.x2, v.x3, v.x4);
}
 
vector6i vector6iAdd(vector6i a, vector6i b){
  vector6i out;
  out.x0 = a.x0+b.x0;
  out.x1 = a.x1+b.x1;
  out.x2 = a.x2+b.x2;
  out.x3 = a.x3+b.x3;
  out.x4 = a.x4+b.x4;
  out.x5 = a.x5+b.x5;
  return out;
}
vector6i vector6iSub(vector6i a, vector6i b){
  vector6i out;
  out.x0 = a.x0-b.x0;
  out.x1 = a.x1-b.x1;
  out.x2 = a.x2-b.x2;
  out.x3 = a.x3-b.x3;
  out.x4 = a.x4-b.x4;
  out.x5 = a.x5-b.x5;
  return out;
}
vector6i vector6iScale(int s,vector6i a){
  vector6i out;
  out.x0 = s*a.x0;
  out.x1 = s*a.x1;
  out.x2 = s*a.x2;
  out.x3 = s*a.x3;
  out.x4 = s*a.x4;
  out.x5 = s*a.x5;
  return out;
}
int vector6iDot(vector6i a, vector6i b){
  int out = 0;
  out += a.x0*b.x0;
  out += a.x1*b.x1;
  out += a.x2*b.x2;
  out += a.x3*b.x3;
  out += a.x4*b.x4;
  out += a.x5*b.x5;
  return out;
}
int vector6iLen(vector6i a){
  int out = 0;
  out += a.x0*a.x0;
  out += a.x1*a.x1;
  out += a.x2*a.x2;
  out += a.x3*a.x3;
  out += a.x4*a.x4;
  out += a.x5*a.x5;
  return ssqrt(out);
}
vector6i vector6iNormalize(vector6i a){return vector6iScale(1/vector6iLen(a),a);}
int vector6iAngle(vector6i a, vector6i b){a = vector6iNormalize(a); b = vector6iNormalize(b);return acos(vector6iDot(a,b));}
void vector6iprint(vector6i v){
  printf("%d, %d, %d, %d, %d, %d",v.x0, v.x1, v.x2, v.x3, v.x4, v.x5);
}
 
vector7i vector7iAdd(vector7i a, vector7i b){
  vector7i out;
  out.x0 = a.x0+b.x0;
  out.x1 = a.x1+b.x1;
  out.x2 = a.x2+b.x2;
  out.x3 = a.x3+b.x3;
  out.x4 = a.x4+b.x4;
  out.x5 = a.x5+b.x5;
  out.x6 = a.x6+b.x6;
  return out;
}
vector7i vector7iSub(vector7i a, vector7i b){
  vector7i out;
  out.x0 = a.x0-b.x0;
  out.x1 = a.x1-b.x1;
  out.x2 = a.x2-b.x2;
  out.x3 = a.x3-b.x3;
  out.x4 = a.x4-b.x4;
  out.x5 = a.x5-b.x5;
  out.x6 = a.x6-b.x6;
  return out;
}
vector7i vector7iScale(int s,vector7i a){
  vector7i out;
  out.x0 = s*a.x0;
  out.x1 = s*a.x1;
  out.x2 = s*a.x2;
  out.x3 = s*a.x3;
  out.x4 = s*a.x4;
  out.x5 = s*a.x5;
  out.x6 = s*a.x6;
  return out;
}
int vector7iDot(vector7i a, vector7i b){
  int out = 0;
  out += a.x0*b.x0;
  out += a.x1*b.x1;
  out += a.x2*b.x2;
  out += a.x3*b.x3;
  out += a.x4*b.x4;
  out += a.x5*b.x5;
  out += a.x6*b.x6;
  return out;
}
int vector7iLen(vector7i a){
  int out = 0;
  out += a.x0*a.x0;
  out += a.x1*a.x1;
  out += a.x2*a.x2;
  out += a.x3*a.x3;
  out += a.x4*a.x4;
  out += a.x5*a.x5;
  out += a.x6*a.x6;
  return ssqrt(out);
}
vector7i vector7iNormalize(vector7i a){return vector7iScale(1/vector7iLen(a),a);}
int vector7iAngle(vector7i a, vector7i b){a = vector7iNormalize(a); b = vector7iNormalize(b);return acos(vector7iDot(a,b));}
void vector7iprint(vector7i v){
  printf("%d, %d, %d, %d, %d, %d, %d",v.x0, v.x1, v.x2, v.x3, v.x4, v.x5, v.x6);
}
 
vector8i vector8iAdd(vector8i a, vector8i b){
  vector8i out;
  out.x0 = a.x0+b.x0;
  out.x1 = a.x1+b.x1;
  out.x2 = a.x2+b.x2;
  out.x3 = a.x3+b.x3;
  out.x4 = a.x4+b.x4;
  out.x5 = a.x5+b.x5;
  out.x6 = a.x6+b.x6;
  out.x7 = a.x7+b.x7;
  return out;
}
vector8i vector8iSub(vector8i a, vector8i b){
  vector8i out;
  out.x0 = a.x0-b.x0;
  out.x1 = a.x1-b.x1;
  out.x2 = a.x2-b.x2;
  out.x3 = a.x3-b.x3;
  out.x4 = a.x4-b.x4;
  out.x5 = a.x5-b.x5;
  out.x6 = a.x6-b.x6;
  out.x7 = a.x7-b.x7;
  return out;
}
vector8i vector8iScale(int s,vector8i a){
  vector8i out;
  out.x0 = s*a.x0;
  out.x1 = s*a.x1;
  out.x2 = s*a.x2;
  out.x3 = s*a.x3;
  out.x4 = s*a.x4;
  out.x5 = s*a.x5;
  out.x6 = s*a.x6;
  out.x7 = s*a.x7;
  return out;
}
int vector8iDot(vector8i a, vector8i b){
  int out = 0;
  out += a.x0*b.x0;
  out += a.x1*b.x1;
  out += a.x2*b.x2;
  out += a.x3*b.x3;
  out += a.x4*b.x4;
  out += a.x5*b.x5;
  out += a.x6*b.x6;
  out += a.x7*b.x7;
  return out;
}
int vector8iLen(vector8i a){
  int out = 0;
  out += a.x0*a.x0;
  out += a.x1*a.x1;
  out += a.x2*a.x2;
  out += a.x3*a.x3;
  out += a.x4*a.x4;
  out += a.x5*a.x5;
  out += a.x6*a.x6;
  out += a.x7*a.x7;
  return ssqrt(out);
}
vector8i vector8iNormalize(vector8i a){return vector8iScale(1/vector8iLen(a),a);}
int vector8iAngle(vector8i a, vector8i b){a = vector8iNormalize(a); b = vector8iNormalize(b);return acos(vector8iDot(a,b));}
void vector8iprint(vector8i v){
  printf("%d, %d, %d, %d, %d, %d, %d, %d",v.x0, v.x1, v.x2, v.x3, v.x4, v.x5, v.x6, v.x7);
}
 
vector9i vector9iAdd(vector9i a, vector9i b){
  vector9i out;
  out.x0 = a.x0+b.x0;
  out.x1 = a.x1+b.x1;
  out.x2 = a.x2+b.x2;
  out.x3 = a.x3+b.x3;
  out.x4 = a.x4+b.x4;
  out.x5 = a.x5+b.x5;
  out.x6 = a.x6+b.x6;
  out.x7 = a.x7+b.x7;
  out.x8 = a.x8+b.x8;
  return out;
}
vector9i vector9iSub(vector9i a, vector9i b){
  vector9i out;
  out.x0 = a.x0-b.x0;
  out.x1 = a.x1-b.x1;
  out.x2 = a.x2-b.x2;
  out.x3 = a.x3-b.x3;
  out.x4 = a.x4-b.x4;
  out.x5 = a.x5-b.x5;
  out.x6 = a.x6-b.x6;
  out.x7 = a.x7-b.x7;
  out.x8 = a.x8-b.x8;
  return out;
}
vector9i vector9iScale(int s,vector9i a){
  vector9i out;
  out.x0 = s*a.x0;
  out.x1 = s*a.x1;
  out.x2 = s*a.x2;
  out.x3 = s*a.x3;
  out.x4 = s*a.x4;
  out.x5 = s*a.x5;
  out.x6 = s*a.x6;
  out.x7 = s*a.x7;
  out.x8 = s*a.x8;
  return out;
}
int vector9iDot(vector9i a, vector9i b){
  int out = 0;
  out += a.x0*b.x0;
  out += a.x1*b.x1;
  out += a.x2*b.x2;
  out += a.x3*b.x3;
  out += a.x4*b.x4;
  out += a.x5*b.x5;
  out += a.x6*b.x6;
  out += a.x7*b.x7;
  out += a.x8*b.x8;
  return out;
}
int vector9iLen(vector9i a){
  int out = 0;
  out += a.x0*a.x0;
  out += a.x1*a.x1;
  out += a.x2*a.x2;
  out += a.x3*a.x3;
  out += a.x4*a.x4;
  out += a.x5*a.x5;
  out += a.x6*a.x6;
  out += a.x7*a.x7;
  out += a.x8*a.x8;
  return ssqrt(out);
}
vector9i vector9iNormalize(vector9i a){return vector9iScale(1/vector9iLen(a),a);}
int vector9iAngle(vector9i a, vector9i b){a = vector9iNormalize(a); b = vector9iNormalize(b);return acos(vector9iDot(a,b));}
void vector9iprint(vector9i v){
  printf("%d, %d, %d, %d, %d, %d, %d, %d, %d",v.x0, v.x1, v.x2, v.x3, v.x4, v.x5, v.x6, v.x7, v.x8);
}
 
vector10i vector10iAdd(vector10i a, vector10i b){
  vector10i out;
  out.x0 = a.x0+b.x0;
  out.x1 = a.x1+b.x1;
  out.x2 = a.x2+b.x2;
  out.x3 = a.x3+b.x3;
  out.x4 = a.x4+b.x4;
  out.x5 = a.x5+b.x5;
  out.x6 = a.x6+b.x6;
  out.x7 = a.x7+b.x7;
  out.x8 = a.x8+b.x8;
  out.x9 = a.x9+b.x9;
  return out;
}
vector10i vector10iSub(vector10i a, vector10i b){
  vector10i out;
  out.x0 = a.x0-b.x0;
  out.x1 = a.x1-b.x1;
  out.x2 = a.x2-b.x2;
  out.x3 = a.x3-b.x3;
  out.x4 = a.x4-b.x4;
  out.x5 = a.x5-b.x5;
  out.x6 = a.x6-b.x6;
  out.x7 = a.x7-b.x7;
  out.x8 = a.x8-b.x8;
  out.x9 = a.x9-b.x9;
  return out;
}
vector10i vector10iScale(int s,vector10i a){
  vector10i out;
  out.x0 = s*a.x0;
  out.x1 = s*a.x1;
  out.x2 = s*a.x2;
  out.x3 = s*a.x3;
  out.x4 = s*a.x4;
  out.x5 = s*a.x5;
  out.x6 = s*a.x6;
  out.x7 = s*a.x7;
  out.x8 = s*a.x8;
  out.x9 = s*a.x9;
  return out;
}
int vector10iDot(vector10i a, vector10i b){
  int out = 0;
  out += a.x0*b.x0;
  out += a.x1*b.x1;
  out += a.x2*b.x2;
  out += a.x3*b.x3;
  out += a.x4*b.x4;
  out += a.x5*b.x5;
  out += a.x6*b.x6;
  out += a.x7*b.x7;
  out += a.x8*b.x8;
  out += a.x9*b.x9;
  return out;
}
int vector10iLen(vector10i a){
  int out = 0;
  out += a.x0*a.x0;
  out += a.x1*a.x1;
  out += a.x2*a.x2;
  out += a.x3*a.x3;
  out += a.x4*a.x4;
  out += a.x5*a.x5;
  out += a.x6*a.x6;
  out += a.x7*a.x7;
  out += a.x8*a.x8;
  out += a.x9*a.x9;
  return ssqrt(out);
}
vector10i vector10iNormalize(vector10i a){return vector10iScale(1/vector10iLen(a),a);}
int vector10iAngle(vector10i a, vector10i b){a = vector10iNormalize(a); b = vector10iNormalize(b);return acos(vector10iDot(a,b));}
void vector10iprint(vector10i v){
  printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d",v.x0, v.x1, v.x2, v.x3, v.x4, v.x5, v.x6, v.x7, v.x8, v.x9);
}
 
vector2i matrix2x2iCol(matrix2x2i v, int col){
            return (vector2i){.x = v.data[0][col], .y = v.data[1][col]};
}
vector2i matrix2x2iRow(matrix2x2i v, int row){
            return (vector2i){.x = v.data[0][row], .y = v.data[1][row]};
}
matrix2x2i matrix2x2iAdd(matrix2x2i a, matrix2x2i b){    matrix2x2i out = {};
    for(int y = 0; y<2; y++){
        for(int x = 0;x<2; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix2x2i matrix2x2iSub(matrix2x2i a, matrix2x2i b){    matrix2x2i out = {};
    for(int y = 0; y<2; y++){
        for(int x = 0;x<2; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector2i matrix2x2iMltVec(matrix2x2i a, vector2i b){
  vector2i out = {vector2iDot(matrix2x2iRow(a, 0), b), vector2iDot(matrix2x2iRow(a, 1), b)};
  return out;
}
matrix2x2i matrix2x2iMlt(matrix2x2i a, matrix2x2i b){
    matrix2x2i out = {};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix2x2i matrix2x2iIdentity(){
  matrix2x2i out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  return out;
}
matrix2x2i matrix2x2iScale(int s, matrix2x2i a){    matrix2x2i out = {};
    for(int y = 0; y<2; y++){
        for(int x = 0;x<2; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix2x2i matrix2x2iTranspose(matrix2x2i a){    matrix2x2i out = {};
    for(int y = 0; y<2; y++){
        for(int x = 0;x<2; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector3i matrix3x3iCol(matrix3x3i v, int col){
            return (vector3i){.x = v.data[0][col], .y = v.data[1][col], .z = v.data[2][col]};
}
vector3i matrix3x3iRow(matrix3x3i v, int row){
            return (vector3i){.x = v.data[row][0], .y = v.data[row][1], .z = v.data[row][2]};
}
matrix3x3i matrix3x3iAdd(matrix3x3i a, matrix3x3i b){    matrix3x3i out = {};
    for(int y = 0; y<3; y++){
        for(int x = 0;x<3; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix3x3i matrix3x3iSub(matrix3x3i a, matrix3x3i b){    matrix3x3i out = {};
    for(int y = 0; y<3; y++){
        for(int x = 0;x<3; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector3i matrix3x3iMltVec(matrix3x3i a, vector3i b){
  vector3i out = {vector3iDot(matrix3x3iRow(a, 0), b), vector3iDot(matrix3x3iRow(a, 1), b),vector3iDot(matrix3x3iRow(a, 2), b)};  return out;
}
matrix3x3i matrix3x3iMlt(matrix3x3i a, matrix3x3i b){
    matrix3x3i out = {};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix3x3i matrix3x3iIdentity(){
  matrix3x3i out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  return out;
}
matrix3x3i matrix3x3iScale(int s, matrix3x3i a){    matrix3x3i out = {};
    for(int y = 0; y<3; y++){
        for(int x = 0;x<3; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix3x3i matrix3x3iTranspose(matrix3x3i a){    matrix3x3i out = {};
    for(int y = 0; y<3; y++){
        for(int x = 0;x<3; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector4i matrix4x4iCol(matrix4x4i v, int col){
            return (vector4i){.w = v.data[0][col],.x = v.data[1][col], .y = v.data[2][col], .z = v.data[3][col]};
}
vector4i matrix4x4iRow(matrix4x4i v, int row){
            return (vector4i){.w = v.data[row][0],.x = v.data[row][1], .y = v.data[row][2], .z = v.data[row][3]};
}
matrix4x4i matrix4x4iAdd(matrix4x4i a, matrix4x4i b){    matrix4x4i out = {};
    for(int y = 0; y<4; y++){
        for(int x = 0;x<4; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix4x4i matrix4x4iSub(matrix4x4i a, matrix4x4i b){    matrix4x4i out = {};
    for(int y = 0; y<4; y++){
        for(int x = 0;x<4; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector4i matrix4x4iMltVec(matrix4x4i a, vector4i b){
  vector4i out = {vector4iDot(matrix4x4iRow(a, 0), b), vector4iDot(matrix4x4iRow(a, 1), b),vector4iDot(matrix4x4iRow(a, 2), b), vector4iDot(matrix4x4iRow(a,3), b)};return out;
}
matrix4x4i matrix4x4iMlt(matrix4x4i a, matrix4x4i b){
    matrix4x4i out = {};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix4x4i matrix4x4iIdentity(){
  matrix4x4i out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  return out;
}
matrix4x4i matrix4x4iScale(int s, matrix4x4i a){    matrix4x4i out = {};
    for(int y = 0; y<4; y++){
        for(int x = 0;x<4; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix4x4i matrix4x4iTranspose(matrix4x4i a){    matrix4x4i out = {};
    for(int y = 0; y<4; y++){
        for(int x = 0;x<4; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector5i matrix5x5iCol(matrix5x5i v, int col){
   vector5i out = {};
  out.x0 = v.data[0][col];
  out.x1 = v.data[1][col];
  out.x2 = v.data[2][col];
  out.x3 = v.data[3][col];
  out.x4 = v.data[4][col];
   return out;
}
vector5i matrix5x5iRow(matrix5x5i v, int row){
   vector5i out = {};
  out.x0 = v.data[row][0];
  out.x1 = v.data[row][1];
  out.x2 = v.data[row][2];
  out.x3 = v.data[row][3];
  out.x4 = v.data[row][4];
   return out;
}
matrix5x5i matrix5x5iAdd(matrix5x5i a, matrix5x5i b){    matrix5x5i out = {};
    for(int y = 0; y<5; y++){
        for(int x = 0;x<5; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix5x5i matrix5x5iSub(matrix5x5i a, matrix5x5i b){    matrix5x5i out = {};
    for(int y = 0; y<5; y++){
        for(int x = 0;x<5; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector5i matrix5x5iMltVec(matrix5x5i a, vector5i b){
  vector5i out = {};
  out.x0 = vector5iDot(matrix5x5iRow(a, 0), b);  out.x1 = vector5iDot(matrix5x5iRow(a, 1), b);  out.x2 = vector5iDot(matrix5x5iRow(a, 2), b);  out.x3 = vector5iDot(matrix5x5iRow(a, 3), b);  out.x4 = vector5iDot(matrix5x5iRow(a, 4), b); 
  return out;
}
matrix5x5i matrix5x5iMlt(matrix5x5i a, matrix5x5i b){
    matrix5x5i out = {};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 5; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix5x5i matrix5x5iIdentity(){
  matrix5x5i out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  out.data[4][4] = 1;
  return out;
}
matrix5x5i matrix5x5iScale(int s, matrix5x5i a){    matrix5x5i out = {};
    for(int y = 0; y<5; y++){
        for(int x = 0;x<5; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix5x5i matrix5x5iTranspose(matrix5x5i a){    matrix5x5i out = {};
    for(int y = 0; y<5; y++){
        for(int x = 0;x<5; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector6i matrix6x6iCol(matrix6x6i v, int col){
   vector6i out = {};
  out.x0 = v.data[0][col];
  out.x1 = v.data[1][col];
  out.x2 = v.data[2][col];
  out.x3 = v.data[3][col];
  out.x4 = v.data[4][col];
  out.x5 = v.data[5][col];
   return out;
}
vector6i matrix6x6iRow(matrix6x6i v, int row){
   vector6i out = {};
  out.x0 = v.data[row][0];
  out.x1 = v.data[row][1];
  out.x2 = v.data[row][2];
  out.x3 = v.data[row][3];
  out.x4 = v.data[row][4];
  out.x5 = v.data[row][5];
   return out;
}
matrix6x6i matrix6x6iAdd(matrix6x6i a, matrix6x6i b){    matrix6x6i out = {};
    for(int y = 0; y<6; y++){
        for(int x = 0;x<6; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix6x6i matrix6x6iSub(matrix6x6i a, matrix6x6i b){    matrix6x6i out = {};
    for(int y = 0; y<6; y++){
        for(int x = 0;x<6; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector6i matrix6x6iMltVec(matrix6x6i a, vector6i b){
  vector6i out = {};
  out.x0 = vector6iDot(matrix6x6iRow(a, 0), b);  out.x1 = vector6iDot(matrix6x6iRow(a, 1), b);  out.x2 = vector6iDot(matrix6x6iRow(a, 2), b);  out.x3 = vector6iDot(matrix6x6iRow(a, 3), b);  out.x4 = vector6iDot(matrix6x6iRow(a, 4), b);  out.x5 = vector6iDot(matrix6x6iRow(a, 5), b); 
  return out;
}
matrix6x6i matrix6x6iMlt(matrix6x6i a, matrix6x6i b){
    matrix6x6i out = {};
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 6; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix6x6i matrix6x6iIdentity(){
  matrix6x6i out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  out.data[4][4] = 1;
  out.data[5][5] = 1;
  return out;
}
matrix6x6i matrix6x6iScale(int s, matrix6x6i a){    matrix6x6i out = {};
    for(int y = 0; y<6; y++){
        for(int x = 0;x<6; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix6x6i matrix6x6iTranspose(matrix6x6i a){    matrix6x6i out = {};
    for(int y = 0; y<6; y++){
        for(int x = 0;x<6; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector7i matrix7x7iCol(matrix7x7i v, int col){
   vector7i out = {};
  out.x0 = v.data[0][col];
  out.x1 = v.data[1][col];
  out.x2 = v.data[2][col];
  out.x3 = v.data[3][col];
  out.x4 = v.data[4][col];
  out.x5 = v.data[5][col];
  out.x6 = v.data[6][col];
   return out;
}
vector7i matrix7x7iRow(matrix7x7i v, int row){
   vector7i out = {};
  out.x0 = v.data[row][0];
  out.x1 = v.data[row][1];
  out.x2 = v.data[row][2];
  out.x3 = v.data[row][3];
  out.x4 = v.data[row][4];
  out.x5 = v.data[row][5];
  out.x6 = v.data[row][6];
   return out;
}
matrix7x7i matrix7x7iAdd(matrix7x7i a, matrix7x7i b){    matrix7x7i out = {};
    for(int y = 0; y<7; y++){
        for(int x = 0;x<7; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix7x7i matrix7x7iSub(matrix7x7i a, matrix7x7i b){    matrix7x7i out = {};
    for(int y = 0; y<7; y++){
        for(int x = 0;x<7; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector7i matrix7x7iMltVec(matrix7x7i a, vector7i b){
  vector7i out = {};
  out.x0 = vector7iDot(matrix7x7iRow(a, 0), b);  out.x1 = vector7iDot(matrix7x7iRow(a, 1), b);  out.x2 = vector7iDot(matrix7x7iRow(a, 2), b);  out.x3 = vector7iDot(matrix7x7iRow(a, 3), b);  out.x4 = vector7iDot(matrix7x7iRow(a, 4), b);  out.x5 = vector7iDot(matrix7x7iRow(a, 5), b);  out.x6 = vector7iDot(matrix7x7iRow(a, 6), b); 
  return out;
}
matrix7x7i matrix7x7iMlt(matrix7x7i a, matrix7x7i b){
    matrix7x7i out = {};
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 7; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix7x7i matrix7x7iIdentity(){
  matrix7x7i out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  out.data[4][4] = 1;
  out.data[5][5] = 1;
  out.data[6][6] = 1;
  return out;
}
matrix7x7i matrix7x7iScale(int s, matrix7x7i a){    matrix7x7i out = {};
    for(int y = 0; y<7; y++){
        for(int x = 0;x<7; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix7x7i matrix7x7iTranspose(matrix7x7i a){    matrix7x7i out = {};
    for(int y = 0; y<7; y++){
        for(int x = 0;x<7; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector8i matrix8x8iCol(matrix8x8i v, int col){
   vector8i out = {};
  out.x0 = v.data[0][col];
  out.x1 = v.data[1][col];
  out.x2 = v.data[2][col];
  out.x3 = v.data[3][col];
  out.x4 = v.data[4][col];
  out.x5 = v.data[5][col];
  out.x6 = v.data[6][col];
  out.x7 = v.data[7][col];
   return out;
}
vector8i matrix8x8iRow(matrix8x8i v, int row){
   vector8i out = {};
  out.x0 = v.data[row][0];
  out.x1 = v.data[row][1];
  out.x2 = v.data[row][2];
  out.x3 = v.data[row][3];
  out.x4 = v.data[row][4];
  out.x5 = v.data[row][5];
  out.x6 = v.data[row][6];
  out.x7 = v.data[row][7];
   return out;
}
matrix8x8i matrix8x8iAdd(matrix8x8i a, matrix8x8i b){    matrix8x8i out = {};
    for(int y = 0; y<8; y++){
        for(int x = 0;x<8; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix8x8i matrix8x8iSub(matrix8x8i a, matrix8x8i b){    matrix8x8i out = {};
    for(int y = 0; y<8; y++){
        for(int x = 0;x<8; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector8i matrix8x8iMltVec(matrix8x8i a, vector8i b){
  vector8i out = {};
  out.x0 = vector8iDot(matrix8x8iRow(a, 0), b);  out.x1 = vector8iDot(matrix8x8iRow(a, 1), b);  out.x2 = vector8iDot(matrix8x8iRow(a, 2), b);  out.x3 = vector8iDot(matrix8x8iRow(a, 3), b);  out.x4 = vector8iDot(matrix8x8iRow(a, 4), b);  out.x5 = vector8iDot(matrix8x8iRow(a, 5), b);  out.x6 = vector8iDot(matrix8x8iRow(a, 6), b);  out.x7 = vector8iDot(matrix8x8iRow(a, 7), b); 
  return out;
}
matrix8x8i matrix8x8iMlt(matrix8x8i a, matrix8x8i b){
    matrix8x8i out = {};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 8; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix8x8i matrix8x8iIdentity(){
  matrix8x8i out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  out.data[4][4] = 1;
  out.data[5][5] = 1;
  out.data[6][6] = 1;
  out.data[7][7] = 1;
  return out;
}
matrix8x8i matrix8x8iScale(int s, matrix8x8i a){    matrix8x8i out = {};
    for(int y = 0; y<8; y++){
        for(int x = 0;x<8; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix8x8i matrix8x8iTranspose(matrix8x8i a){    matrix8x8i out = {};
    for(int y = 0; y<8; y++){
        for(int x = 0;x<8; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector9i matrix9x9iCol(matrix9x9i v, int col){
   vector9i out = {};
  out.x0 = v.data[0][col];
  out.x1 = v.data[1][col];
  out.x2 = v.data[2][col];
  out.x3 = v.data[3][col];
  out.x4 = v.data[4][col];
  out.x5 = v.data[5][col];
  out.x6 = v.data[6][col];
  out.x7 = v.data[7][col];
  out.x8 = v.data[8][col];
   return out;
}
vector9i matrix9x9iRow(matrix9x9i v, int row){
   vector9i out = {};
  out.x0 = v.data[row][0];
  out.x1 = v.data[row][1];
  out.x2 = v.data[row][2];
  out.x3 = v.data[row][3];
  out.x4 = v.data[row][4];
  out.x5 = v.data[row][5];
  out.x6 = v.data[row][6];
  out.x7 = v.data[row][7];
  out.x8 = v.data[row][8];
   return out;
}
matrix9x9i matrix9x9iAdd(matrix9x9i a, matrix9x9i b){    matrix9x9i out = {};
    for(int y = 0; y<9; y++){
        for(int x = 0;x<9; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix9x9i matrix9x9iSub(matrix9x9i a, matrix9x9i b){    matrix9x9i out = {};
    for(int y = 0; y<9; y++){
        for(int x = 0;x<9; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector9i matrix9x9iMltVec(matrix9x9i a, vector9i b){
  vector9i out = {};
  out.x0 = vector9iDot(matrix9x9iRow(a, 0), b);  out.x1 = vector9iDot(matrix9x9iRow(a, 1), b);  out.x2 = vector9iDot(matrix9x9iRow(a, 2), b);  out.x3 = vector9iDot(matrix9x9iRow(a, 3), b);  out.x4 = vector9iDot(matrix9x9iRow(a, 4), b);  out.x5 = vector9iDot(matrix9x9iRow(a, 5), b);  out.x6 = vector9iDot(matrix9x9iRow(a, 6), b);  out.x7 = vector9iDot(matrix9x9iRow(a, 7), b);  out.x8 = vector9iDot(matrix9x9iRow(a, 8), b); 
  return out;
}
matrix9x9i matrix9x9iMlt(matrix9x9i a, matrix9x9i b){
    matrix9x9i out = {};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 9; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix9x9i matrix9x9iIdentity(){
  matrix9x9i out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  out.data[4][4] = 1;
  out.data[5][5] = 1;
  out.data[6][6] = 1;
  out.data[7][7] = 1;
  out.data[8][8] = 1;
  return out;
}
matrix9x9i matrix9x9iScale(int s, matrix9x9i a){    matrix9x9i out = {};
    for(int y = 0; y<9; y++){
        for(int x = 0;x<9; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix9x9i matrix9x9iTranspose(matrix9x9i a){    matrix9x9i out = {};
    for(int y = 0; y<9; y++){
        for(int x = 0;x<9; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
vector10i matrix10x10iCol(matrix10x10i v, int col){
   vector10i out = {};
  out.x0 = v.data[0][col];
  out.x1 = v.data[1][col];
  out.x2 = v.data[2][col];
  out.x3 = v.data[3][col];
  out.x4 = v.data[4][col];
  out.x5 = v.data[5][col];
  out.x6 = v.data[6][col];
  out.x7 = v.data[7][col];
  out.x8 = v.data[8][col];
  out.x9 = v.data[9][col];
   return out;
}
vector10i matrix10x10iRow(matrix10x10i v, int row){
   vector10i out = {};
  out.x0 = v.data[row][0];
  out.x1 = v.data[row][1];
  out.x2 = v.data[row][2];
  out.x3 = v.data[row][3];
  out.x4 = v.data[row][4];
  out.x5 = v.data[row][5];
  out.x6 = v.data[row][6];
  out.x7 = v.data[row][7];
  out.x8 = v.data[row][8];
  out.x9 = v.data[row][9];
   return out;
}
matrix10x10i matrix10x10iAdd(matrix10x10i a, matrix10x10i b){    matrix10x10i out = {};
    for(int y = 0; y<10; y++){
        for(int x = 0;x<10; x++){
                out.data[y][x] = a.data[y][x]+b.data[y][x];
        }
    }
    return out;
}
matrix10x10i matrix10x10iSub(matrix10x10i a, matrix10x10i b){    matrix10x10i out = {};
    for(int y = 0; y<10; y++){
        for(int x = 0;x<10; x++){
                out.data[y][x] = a.data[y][x]-b.data[y][x];
        }
    }
    return out;
}
vector10i matrix10x10iMltVec(matrix10x10i a, vector10i b){
  vector10i out = {};
  out.x0 = vector10iDot(matrix10x10iRow(a, 0), b);  out.x1 = vector10iDot(matrix10x10iRow(a, 1), b);  out.x2 = vector10iDot(matrix10x10iRow(a, 2), b);  out.x3 = vector10iDot(matrix10x10iRow(a, 3), b);  out.x4 = vector10iDot(matrix10x10iRow(a, 4), b);  out.x5 = vector10iDot(matrix10x10iRow(a, 5), b);  out.x6 = vector10iDot(matrix10x10iRow(a, 6), b);  out.x7 = vector10iDot(matrix10x10iRow(a, 7), b);  out.x8 = vector10iDot(matrix10x10iRow(a, 8), b);  out.x9 = vector10iDot(matrix10x10iRow(a, 9), b); 
  return out;
}
matrix10x10i matrix10x10iMlt(matrix10x10i a, matrix10x10i b){
    matrix10x10i out = {};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            out.data[i][j] = 0;
            for (int k = 0; k < 10; k++) {
                out.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return out;
}
matrix10x10i matrix10x10iIdentity(){
  matrix10x10i out = {};
  out.data[0][0] = 1;
  out.data[1][1] = 1;
  out.data[2][2] = 1;
  out.data[3][3] = 1;
  out.data[4][4] = 1;
  out.data[5][5] = 1;
  out.data[6][6] = 1;
  out.data[7][7] = 1;
  out.data[8][8] = 1;
  out.data[9][9] = 1;
  return out;
}
matrix10x10i matrix10x10iScale(int s, matrix10x10i a){    matrix10x10i out = {};
    for(int y = 0; y<10; y++){
        for(int x = 0;x<10; x++){
                out.data[y][x] = a.data[y][x]*s;
        }
    }
    return out;
}
matrix10x10i matrix10x10iTranspose(matrix10x10i a){    matrix10x10i out = {};
    for(int y = 0; y<10; y++){
        for(int x = 0;x<10; x++){
                out.data[y][x] = a.data[x][y];
        }
    }
    return out;
}
#endif