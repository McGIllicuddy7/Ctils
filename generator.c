#define CTILS_IMPLEMENTATION
#include "utils.h"
#include <stdio.h>
String generate_pre_header_code(){
    return new_string("#pragma once\n#include \"utils.h\"\n#include <math.h>\n#include <complex.h>\n//use #define UTILS_MATH_IMPLEMENTATION to compile\n\n");
}
String generate_vector_header(const char * type, const char * type_alias,int dimension){
    String out = new_string("");
    String fields;
    if(dimension == 2){
        fields = string_format(" %s x;\n %s y;\n", type, type);
    } else if(dimension == 3){
        fields =string_format(" %s x;\n %s y;\n %s z;\n", type, type, type);
    } else if(dimension == 4){
        fields =string_format(" %s w;\n %s x;\n %s y;\n %s z;\n", type, type, type, type);
    } else{
        fields = new_string("");
        for(int i =0; i<dimension; i++){
            String tmp = string_format("    %s x%d;\n", type,i);
            str_concat(fields, tmp);
            destroy(tmp);
        }
    }
    String name = string_format("vector%d%s",dimension, type_alias);
    String strct = string_format("\ntypedef struct{\n%s}%s;\n", fields,name);
    String func_names = string_format(
"%s %sAdd(%s a, %s b);\n\
%s %sSub(%s a, %s b);\n\
%s %sDot(%s a, %s b);\n\
%s %sScale(%s s, %s a);\n\
%s %sLen(%s a);\n\
%s %sNormalize(%s a);\n\
%s %sAngle(%s a, %s b);\n\
\n\
",
                        name, name, name, name,
                        name, name, name, name,
                        type, name, name, name,
                        name, name, type, name,
                        type,name,name,
                        name, name, name,
                        type, name, name, name
                        );
    str_concat(out, strct);
    str_concat(out, func_names);
    destroy(fields);
    destroy(name);
    destroy(strct);
    destroy(func_names);
    return out;
}
String generate_code_header(){
    return string_format("");
}
String generate_add_code(const char * type, const char * type_alias, int dimension){
    if(dimension == 2){
        return string_format("vector%d%s vector%d%sAdd(vector%d%s a, vector%d%s b){\n  return (vector%d%s){a.x +b.x, a.y+b.y};\n}\n",
        dimension,type_alias,
        dimension,type_alias,
        dimension,type_alias,       
        dimension,type_alias,
        dimension,type_alias);
    }
    else if(dimension == 3){
        return string_format("vector%d%s vector%d%sAdd(vector%d%s a, vector%d%s b){\n  return (vector%d%s){a.x +b.x, a.y+b.y, a.z+b.z};\n}\n",
        dimension,type_alias,
        dimension,type_alias,
        dimension,type_alias,       
        dimension,type_alias,
        dimension,type_alias);
    }
    else if(dimension == 4){
        return string_format("vector%d%s vector%d%sAdd(vector%d%s a, vector%d%s b){\n  return (vector%d%s){a.w+b.w,a.x+b.x, a.y+b.y, a.z+b.z};\n}\n",
        dimension,type_alias,
        dimension,type_alias,
        dimension,type_alias,       
        dimension,type_alias,
        dimension,type_alias);
    }
    else{
        String base = string_format("vector%d%s vector%d%sAdd(vector%d%s a, vector%d%s b){\n  vector%d%s out;\n",
        dimension,type_alias,
        dimension,type_alias,
        dimension,type_alias,       
        dimension,type_alias,
        dimension,type_alias);
        for(int i =0; i<dimension; i++){
            String tmp = string_format("  out.x%d = a.x%d+b.x%d;\n", i,i,i);
            str_concat(base, tmp);
            destroy(tmp);
        }
        String tmp = new_string("  return out;\n}\n");
        str_concat(base, tmp);
        destroy(tmp);
        return base;
    }
}
String generate_sub_code(const char * type, const char * type_alias, int dimension){
    if(dimension == 2){
        return string_format("vector%d%s vector%d%sSub(vector%d%s a, vector%d%s b){\n  return (vector%d%s){a.x-b.x, a.y-b.y};\n}\n",
        dimension,type_alias,
        dimension,type_alias,
        dimension,type_alias,       
        dimension,type_alias,
        dimension,type_alias);
    }
    else if(dimension == 3){
        return string_format("vector%d%s vector%d%sSub(vector%d%s a, vector%d%s b){\n  return (vector%d%s){a.x-b.x, a.y-b.y, a.z-b.z};\n}\n",
        dimension,type_alias,
        dimension,type_alias,
        dimension,type_alias,       
        dimension,type_alias,
        dimension,type_alias);
    }
    else if(dimension == 4){
        return string_format("vector%d%s vector%d%sSub(vector%d%s a, vector%d%s b){\n  return (vector%d%s){a.w-b.w,a.x-b.x, a.y-b.y, a.z-b.z};\n}\n",
        dimension,type_alias,
        dimension,type_alias,
        dimension,type_alias,       
        dimension,type_alias,
        dimension,type_alias);
    }
    else{
        String base = string_format("vector%d%s vector%d%sSub(vector%d%s a, vector%d%s b){\n  vector%d%s out;\n",
        dimension,type_alias,
        dimension,type_alias,
        dimension,type_alias,       
        dimension,type_alias,
        dimension,type_alias);
        for(int i =0; i<dimension; i++){
            String tmp = string_format("  out.x%d = a.x%d-b.x%d;\n", i,i,i);
            str_concat(base, tmp);
            destroy(tmp);
        }
        String tmp = new_string("  return out;\n}\n");
        str_concat(base, tmp);
        destroy(tmp);
        return base;
    }
}
String generate_scale_code(const char * type, const char * type_alias, int dimension){
    if(dimension == 2){
        return string_format("vector%d%s vector%d%sScale(%s s, vector%d%s a){\n  return (vector%d%s){a.x*s, a.y*s};\n}\n",
        dimension,type_alias,
        dimension,type_alias,
        type, 
        dimension,type_alias,
        dimension,type_alias);
    }
    else if(dimension == 3){
        return string_format("vector%d%s vector%d%sScale(%s s, vector%d%s a){\n  return (vector%d%s){a.x*s, a.y*s, a.z*s};\n}\n",
        dimension,type_alias,
        dimension,type_alias,
        type, 
        dimension,type_alias,
        dimension,type_alias);
    }
    else if(dimension == 4){
        return string_format("vector%d%s vector%d%sScale(%s s, vector%d%s a){\n  return (vector%d%s){a.w*s,a.x*s, a.y*s, a.z*s};\n}\n",
        dimension,type_alias,
        dimension,type_alias,
        type, 
        dimension,type_alias,
        dimension,type_alias);
    }
    else{
        String base = string_format("vector%d%s vector%d%sScale(%s s,vector%d%s a){\n  vector%d%s out;\n",
        dimension,type_alias,
        dimension,type_alias,
        type,      
        dimension,type_alias,
        dimension,type_alias);
        for(int i =0; i<dimension; i++){
            String tmp = string_format("  out.x%d = s*a.x%d;\n", i,i,i);
            str_concat(base, tmp);
            destroy(tmp);
        }
        String tmp = new_string("  return out;\n}\n");
        str_concat(base, tmp);
        destroy(tmp);
        return base;
    }
}
String generate_dot_product_code(const char * type, const char * type_alias, int dimension){
    if(dimension == 2){
        return string_format("%s vector%d%sDot(vector%d%s a, vector%d%s b){\n  return a.x*b.x+a.y*b.y;\n}\n",
        type,
        dimension,type_alias,
        dimension,type_alias,       
        dimension,type_alias,
        dimension,type_alias);
    }
    if(dimension == 3){
        return string_format("%s vector%d%sDot(vector%d%s a, vector%d%s b){\n  return a.x*b.x+a.y*b.y+a.z*b.z;\n}\n",
        type,
        dimension,type_alias,
        dimension,type_alias,       
        dimension,type_alias,
        dimension,type_alias);
    }
    if(dimension == 4){
        return string_format("%s vector%d%sDot(vector%d%s a, vector%d%s b){\n  return a.w*b.w+a.x*b.x+a.y*b.y+a.z*b.z;\n}\n",
        type,
        dimension,type_alias,
        dimension,type_alias,       
        dimension,type_alias,
        dimension,type_alias);
    }
    else{
        String base = string_format("%s vector%d%sDot(vector%d%s a, vector%d%s b){\n  %s out = 0;\n",
        type,
        dimension,type_alias,
        dimension,type_alias,       
        dimension,type_alias,
        type);
        for(int i =0; i<dimension; i++){
            String tmp = string_format("  out += a.x%d*b.x%d;\n",i,i);
            str_concat(base, tmp);
            destroy(tmp);
        }
        String tmp = new_string("  return out;\n}\n");
        str_concat(base, tmp);
        destroy(tmp);
        return base;
    }
}
String generate_len_code(const char * type, const char * type_alias, const char * sqrt_func,int dimension){
    if(dimension == 2){
        return string_format("%s vector%d%sLen(vector%d%s a){\n  return %s(a.x*a.x+a.y*a.y);\n}\n",
        type,
        dimension,type_alias,
        dimension,type_alias,
        sqrt_func
        );
    }
    if(dimension == 3){
        return string_format("%s vector%d%sLen(vector%d%s a){\n  return %s(a.x*a.x+a.y*a.y+a.z*a.z);\n}\n",
        type,
        dimension,type_alias,
        dimension,type_alias,
        sqrt_func
        );
    }
    if(dimension == 4){
        return string_format("%s vector%d%sLen(vector%d%s a){\n  return %s(a.w*a.w+a.x*a.x+a.y*a.y+a.z*a.z);\n}\n",
        type,
        dimension,type_alias,
        dimension,type_alias,
        sqrt_func
        );
    }
    else{
        String base = string_format("%s vector%d%sLen(vector%d%s a){\n  %s out = 0;\n",
        type,
        dimension,type_alias,
        dimension,type_alias,       
        type);
        for(int i =0; i<dimension; i++){
            String tmp = string_format("  out += a.x%d*a.x%d;\n",i,i);
            str_concat(base, tmp);
            destroy(tmp);
        }
        String tmp = string_format("  return %s(out);\n}\n", sqrt_func);
        str_concat(base, tmp);
        destroy(tmp);
        return base;
    }
}
String generate_normalize_code(const char * type, const char * type_alias, int dimension){
    return string_format("vector%d%s vector%d%sNormalize(vector%d%s a){return vector%d%sScale(1/vector%d%sLen(a),a);}\n", 
    dimension,type_alias,
    dimension,type_alias,
    dimension,type_alias,
    dimension,type_alias,
    dimension,type_alias
    );
}
String generate_angle_code(const char * type, const char * type_alias, const char * inverses_cos, int dimension){
    return string_format("%s vector%d%sAngle(vector%d%s a, vector%d%s b){a = vector%d%sNormalize(a); b = vector%d%sNormalize(b);return %s(vector%d%sDot(a,b));}\n", 
    type,
    dimension,type_alias,
    dimension,type_alias,
    dimension,type_alias,
    dimension,type_alias,
    dimension,type_alias,
    inverses_cos, 
    dimension, type_alias
    );
} 
String generate_vector_code(const char * type, const char * type_alias,const char * sqrt_func, const char * inverse_cos_func, int dimension){
    String out = new_string("");
    String add = generate_add_code(type, type_alias, dimension);
    String sub = generate_sub_code(type, type_alias, dimension);
    String scale = generate_scale_code(type, type_alias, dimension);
    String dot = generate_dot_product_code(type, type_alias, dimension);
    String length = generate_len_code(type, type_alias, sqrt_func, dimension);
    String normalize = generate_normalize_code(type, type_alias, dimension);
    String angle = generate_angle_code(type, type_alias, inverse_cos_func, dimension);
    str_concat(out, add);
    str_concat(out, sub);
    str_concat(out, scale);
    str_concat(out, dot);
    str_concat(out, length); 
    str_concat(out, normalize);
    str_concat(out, angle);
    destroy(add);
    destroy(sub);
    destroy(scale);
    destroy(dot);
    destroy(length);
    destroy(normalize);
    destroy(angle);
    return out;
}
String generate_code_footer(){
    return 0;
}
String generate_matrix_header(const char * type, const char * type_alias, int dimension){ 
    String out = new_string("");
    String name = string_format("matrix%dx%d%s", dimension, dimension,type_alias);
    String vec_name = string_format("vector%d%s",dimension, type_alias);
    String strct = string_format("typedef struct {\n  %s data[%d][%d];\n}%s;\n", type, dimension, dimension, name);
    String func_names = string_format(
"%s %sAdd(%s a, %s b);\n\
%s %sSub(%s a, %s b);\n\
%s %sMlt(%s a, %s b);\n\
%s %sMltVec(%s a, %s b);\n\
%s %sScale(%s s, %s a);\n\
%s %sRow(%s m,int row);\n\
%s %sCol(%s m, int col);\n\
%s %sInverse(%s a);\n\
%s %sDeterminant(%s a);\n\
%s %sIdentity();\n\
\n\
",
        name, name, name, name,
        name, name, name, name,
        name, name, name, name,
        vec_name, name, name,vec_name,
        name, name, type, name,
        vec_name, name,name,
        vec_name, name,name,
        name, name, name,
        name, name,name,
        name,name,name
    ); 
    str_concat(out, strct);
    str_concat(out, func_names);
    destroy(name);
    destroy(strct);
    destroy(func_names); 
    return out;
}
String generate_m_col_function(const char * type, const char * type_alias, int dimension){
    String name = string_format("matrix%dx%d%s", dimension, dimension,type_alias);
    String vec_name = string_format("vector%d%s",dimension, type_alias);
    String out;
    if(dimension == 2){
        out = string_format("%s %sCol(%s v, int col){\n\
            return (%s){.x = v.data[0][col], .y = v.data[1][col]};\n}\n", 
        vec_name, name, name, vec_name);
    } else if(dimension == 3){
        out = string_format("%s %sCol(%s v, int col){\n\
            return (%s){.x = v.data[0][col], .y = v.data[1][col], .z = v.data[2][col]};\n}\n", 
        vec_name, name, name, vec_name);
    } else if(dimension == 4){
        out = string_format("%s %sCol(%s v, int col){\n\
            return (%s){.w = v.data[0][col],.x = v.data[1][col], .y = v.data[2][col], .z = v.data[3][col]};\n}\n", 
        vec_name, name, name, vec_name);
    } else{
        out = string_format("%s %sCol(%s v, int col){\n   %s out = {};\n", vec_name, name, name, vec_name);
        for(int i =0; i<dimension; i++){
            String tmp = string_format("  out.x%d = v.data[%d][col];\n", i,i);
            str_concat(out, tmp);
            destroy(tmp);
        }
        str_concat(out, "   return out;\n}\n");
    }
    destroy(name);
    destroy(vec_name);
    return out;
}
String generate_m_row_function(const char * type, const char * type_alias, int dimension){
    String name = string_format("matrix%dx%d%s", dimension, dimension,type_alias);
    String vec_name = string_format("vector%d%s",dimension, type_alias);
    String out;
    if(dimension == 2){
        out = string_format("%s %sRow(%s v, int row){\n\
            return (%s){.x = v.data[0][row], .y = v.data[1][row]};\n}\n", 
        vec_name, name, name, vec_name);
    } else if(dimension == 3){
        out = string_format("%s %sRow(%s v, int row){\n\
            return (%s){.x = v.data[row][0], .y = v.data[row][1], .z = v.data[row][2]};\n}\n", 
        vec_name, name, name, vec_name);
    } else if(dimension == 4){
        out = string_format("%s %sRow(%s v, int row){\n\
            return (%s){.w = v.data[row][0],.x = v.data[row][1], .y = v.data[row][2], .z = v.data[row][3]};\n}\n", 
        vec_name, name, name, vec_name);
    } else{
        out = string_format("%s %sRow(%s v, int row){\n   %s out = {};\n", vec_name, name, name, vec_name);
        for(int i =0; i<dimension; i++){
            String tmp = string_format("  out.x%d = v.data[row][%d];\n", i,i);
            str_concat(out, tmp);
            destroy(tmp);
        }
        str_concat(out, "   return out;\n}\n");
    }
    destroy(name);
    destroy(vec_name);
    return out;
}
String generate_m_add_function(const char * type, const char * type_alias, int dimension){
    String name = string_format("matrix%dx%d%s", dimension, dimension,type_alias);
    String out = string_format("%s %sAdd(%s a, %s b){\
    %s out = {};\n\
    for(int y = 0; y<%d; y++){\n\
        for(int x = 0;x<%d; x++){\n\
                out.data[y][x] = a.data[y][x]+b.data[y][x];\n\
        }\n\
    }\n\
    return out;\n\
}\n", name, name, name, name, name, dimension, dimension);
    destroy(name);
    return out;
}
String generate_m_sub_function(const char * type, const char * type_alias, int dimension){
    String name = string_format("matrix%dx%d%s", dimension, dimension,type_alias);
    String out = string_format("%s %sSub(%s a, %s b){\
    %s out = {};\n\
    for(int y = 0; y<%d; y++){\n\
        for(int x = 0;x<%d; x++){\n\
                out.data[y][x] = a.data[y][x]-b.data[y][x];\n\
        }\n\
    }\n\
    return out;\n\
}\n", name, name, name, name, name, dimension, dimension);
    destroy(name);
    return out;
}
String generate_m_mlt_vec_function(const char * type, const char * type_alias, int dimension){
    String name = string_format("matrix%dx%d%s", dimension, dimension,type_alias);
    String vec_name = string_format("vector%d%s",dimension, type_alias);
    String out;
    if(dimension == 2){
        out = string_format("%s %sMltVec(%s a, %s b){\n  %s out = {%sDot(%sRow(a, 0), b), %sDot(%sRow(a, 1), b)};\n  return out;\n}\n", vec_name, name, name, vec_name, vec_name, vec_name, name, vec_name,name);
    } else if(dimension == 3){
        out = string_format("%s %sMltVec(%s a, %s b){\n  %s out = {%sDot(%sRow(a, 0), b), %sDot(%sRow(a, 1), b),%sDot(%sRow(a, 2), b)};  return out;\n}\n", vec_name, name, name, vec_name, vec_name, vec_name, name, vec_name,name, vec_name, name);
    } else if(dimension == 4){
        out = string_format("%s %sMltVec(%s a, %s b){\n  %s out = {%sDot(%sRow(a, 0), b), %sDot(%sRow(a, 1), b),%sDot(%sRow(a, 2), b), %sDot(%sRow(a,3), b)};return out;\n}\n", vec_name, name, name, vec_name, vec_name, vec_name, name, vec_name,name, vec_name, name,vec_name, name);
    } else{
    out = string_format("%s %sMltVec(%s a, %s b){\n  %s out = {};\n", vec_name, name, name, vec_name, vec_name);
    for(int i =0; i<dimension; i++){
        String tmp = string_format("  out.x%d = %sDot(%sRow(a, %d), b);", i, vec_name, name, i);
        str_concat(out, tmp);
        destroy(tmp);
    }
        str_concat(out, " \n  return out;\n}\n");
    }

    destroy(name);
    destroy(vec_name);
    return out; 
}
String generate_m_mlt_function(const char * type, const char * type_alias, int dimension){
    String name = string_format("matrix%dx%d%s", dimension, dimension,type_alias);
    String vec_name = string_format("vector%d%s",dimension, type_alias);
    String out = string_format("%s %sMlt(%s a, %s b){\n\
    %s out = {};\n\
    for (int i = 0; i < %d; i++) {\
        for (int j = 0; j < %d; j++) {\
            out.data[i][j] = 0;\
            for (int k = 0; k < %d; k++) {\
                out.data[i][j] += a.data[i][k] * b.data[k][j];\
            }\
        }\
    }\
    return out;\n\
}\n", name, name, name, name, name, dimension, dimension, dimension);
    destroy(name);
    destroy(vec_name);
    return out;
}
String generate_matrix_functions(const char * type, const char * type_alias, int dimension){
    String out = new_string("");
    String col = generate_m_col_function(type, type_alias, dimension);
    String row = generate_m_row_function(type, type_alias, dimension);
    String add = generate_m_add_function(type, type_alias, dimension);
    String sub = generate_m_sub_function(type, type_alias, dimension);
    String mlt_v =generate_m_mlt_vec_function(type, type_alias, dimension);  
    String mlt =generate_m_mlt_function(type, type_alias, dimension); 
    str_concat(out, col);
    str_concat(out, row);
    str_concat(out, add);
    str_concat(out, sub);
    str_concat(out, mlt_v);
    str_concat(out, mlt);
    destroy(col);
    destroy(row);
    destroy(add);
    destroy(sub);
    destroy(mlt_v);
    destroy(mlt);
    return out;
}
int main(int argc, const char ** argv){
    String to_write = new_string("");
    String header = generate_pre_header_code();
    str_concat(to_write, header);
    destroy(header);
    for(int i =2; i<6; i++){
        String tmp = generate_vector_header("double", "d", i);
        str_concat(to_write, tmp);
        destroy(tmp);
    }
    for(int i =2; i<6; i++){
        String tmp = generate_matrix_header("double", "d",i);
        str_concat(to_write, tmp);
        destroy(tmp); 
    }
    for(int i =2; i<6; i++){
        String tmp = generate_vector_code("double", "d","sqrt", "acos",i);
        str_concat(to_write, tmp);
        str_append(to_write, '\n');
        destroy(tmp);
    }
   for(int i =2; i<6; i++){
        String tmp = generate_matrix_functions("double", "d",i);
        str_concat(to_write, tmp);
        destroy(tmp); 
    }
    write_string_to_file(to_write, "utils_math.h");
    destroy(to_write);
}