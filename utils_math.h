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
#endif