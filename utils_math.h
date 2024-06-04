#pragma once
#include "utils.h"
#include <math.h>
#include <complex.h>
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

typedef struct {
  double values[2][2];
}matrix2x2d;
matrix2x2d matrix2x2dAdd(matrix2x2d a, matrix2x2d b);
matrix2x2d matrix2x2dSub(matrix2x2d a, matrix2x2d b);
matrix2x2d matrix2x2dMlt(matrix2x2d a, matrix2x2d b);
matrix2x2d matrix2x2dScale(double s, matrix2x2d a);
vector2d matrix2x2dGetRow(int row);
vector2d matrix2x2dGetCol(int col);
matrix2x2d matrix2x2dInverse(matrix2x2d a);

typedef struct {
  double values[3][3];
}matrix3x3d;
matrix3x3d matrix3x3dAdd(matrix3x3d a, matrix3x3d b);
matrix3x3d matrix3x3dSub(matrix3x3d a, matrix3x3d b);
matrix3x3d matrix3x3dMlt(matrix3x3d a, matrix3x3d b);
matrix3x3d matrix3x3dScale(double s, matrix3x3d a);
vector3d matrix3x3dGetRow(int row);
vector3d matrix3x3dGetCol(int col);
matrix3x3d matrix3x3dInverse(matrix3x3d a);

typedef struct {
  double values[4][4];
}matrix4x4d;
matrix4x4d matrix4x4dAdd(matrix4x4d a, matrix4x4d b);
matrix4x4d matrix4x4dSub(matrix4x4d a, matrix4x4d b);
matrix4x4d matrix4x4dMlt(matrix4x4d a, matrix4x4d b);
matrix4x4d matrix4x4dScale(double s, matrix4x4d a);
vector4d matrix4x4dGetRow(int row);
vector4d matrix4x4dGetCol(int col);
matrix4x4d matrix4x4dInverse(matrix4x4d a);

typedef struct {
  double values[5][5];
}matrix5x5d;
matrix5x5d matrix5x5dAdd(matrix5x5d a, matrix5x5d b);
matrix5x5d matrix5x5dSub(matrix5x5d a, matrix5x5d b);
matrix5x5d matrix5x5dMlt(matrix5x5d a, matrix5x5d b);
matrix5x5d matrix5x5dScale(double s, matrix5x5d a);
vector5d matrix5x5dGetRow(int row);
vector5d matrix5x5dGetCol(int col);
matrix5x5d matrix5x5dInverse(matrix5x5d a);

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

