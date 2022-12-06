//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// eml_setop.cpp
//
// Code generation for function 'eml_setop'
//

// Include files
#include "eml_setop.h"
#include "a_opt_mex_data.h"
#include "issorted.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRTEInfo b_emlrtRTEI{
    218,          // lineNo
    13,           // colNo
    "do_vectors", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pName
};

static emlrtRTEInfo c_emlrtRTEI{
    215,          // lineNo
    13,           // colNo
    "do_vectors", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pName
};

static emlrtRTEInfo e_emlrtRTEI{
    382,          // lineNo
    5,            // colNo
    "do_vectors", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pName
};

static emlrtRTEInfo f_emlrtRTEI{
    393,          // lineNo
    9,            // colNo
    "do_vectors", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pName
};

static emlrtRTEInfo g_emlrtRTEI{
    420,          // lineNo
    5,            // colNo
    "do_vectors", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pName
};

// Function Definitions
namespace coder {
void do_vectors(const emlrtStack *sp, const real_T a[2], const real_T b[2],
                real_T c_data[], int32_T c_size[2], int32_T ia_data[],
                int32_T *ia_size, int32_T ib_data[], int32_T *ib_size)
{
  int32_T b_ialast;
  int32_T b_iblast;
  int32_T iafirst;
  int32_T ialast;
  int32_T ibfirst;
  int32_T iblast;
  int32_T nc;
  int32_T nia;
  int32_T nib;
  c_size[0] = 1;
  if ((!(a[0] <= a[1])) && (!muDoubleScalarIsNaN(a[1]))) {
    emlrtErrorWithMessageIdR2018a(sp, &c_emlrtRTEI,
                                  "Coder:toolbox:eml_setop_unsortedA",
                                  "Coder:toolbox:eml_setop_unsortedA", 0);
  }
  if ((!(b[0] <= b[1])) && (!muDoubleScalarIsNaN(b[1]))) {
    emlrtErrorWithMessageIdR2018a(sp, &b_emlrtRTEI,
                                  "Coder:toolbox:eml_setop_unsortedB",
                                  "Coder:toolbox:eml_setop_unsortedB", 0);
  }
  nc = -1;
  nia = -1;
  nib = -1;
  iafirst = 1;
  ialast = 0;
  ibfirst = 0;
  iblast = 0;
  while ((ialast + 1 <= 2) && (iblast + 1 <= 2)) {
    real_T ak;
    real_T bk;
    b_ialast = ialast + 1;
    ak = a[ialast];
    while ((b_ialast < 2) && (a[1] == ak)) {
      b_ialast = 2;
    }
    ialast = b_ialast - 1;
    b_iblast = iblast + 1;
    bk = b[iblast];
    while ((b_iblast < 2) && (b[1] == bk)) {
      b_iblast = 2;
    }
    iblast = b_iblast - 1;
    if (ak == bk) {
      nc++;
      c_data[nc] = ak;
      nia++;
      ia_data[nia] = iafirst;
      ialast = b_ialast;
      iafirst = b_ialast + 1;
      iblast = b_iblast;
      ibfirst = b_iblast;
    } else {
      boolean_T p;
      if (muDoubleScalarIsNaN(bk)) {
        p = !muDoubleScalarIsNaN(ak);
      } else if (muDoubleScalarIsNaN(ak)) {
        p = false;
      } else {
        p = (ak < bk);
      }
      if (p) {
        nc++;
        nia++;
        c_data[nc] = ak;
        ia_data[nia] = iafirst;
        ialast = b_ialast;
        iafirst = b_ialast + 1;
      } else {
        nc++;
        nib++;
        c_data[nc] = bk;
        ib_data[nib] = ibfirst + 1;
        iblast = b_iblast;
        ibfirst = b_iblast;
      }
    }
  }
  while (ialast + 1 <= 2) {
    b_ialast = ialast + 1;
    while ((b_ialast < 2) && (a[1] == a[ialast])) {
      b_ialast = 2;
    }
    nc++;
    nia++;
    c_data[nc] = a[ialast];
    ia_data[nia] = iafirst;
    ialast = b_ialast;
    iafirst = b_ialast + 1;
  }
  while (iblast + 1 <= 2) {
    b_iblast = iblast + 1;
    while ((b_iblast < 2) && (b[1] == b[iblast])) {
      b_iblast = 2;
    }
    nc++;
    nib++;
    c_data[nc] = b[iblast];
    ib_data[nib] = ibfirst + 1;
    iblast = b_iblast;
    ibfirst = b_iblast;
  }
  if (nia + 1 < 1) {
    nia = -1;
  }
  for (iafirst = 0; iafirst <= nia; iafirst++) {
    ia_data[iafirst] = static_cast<int8_T>(ia_data[iafirst]);
  }
  *ia_size = nia + 1;
  if (nib + 1 < 1) {
    nia = -1;
  } else {
    nia = nib;
  }
  for (iafirst = 0; iafirst <= nia; iafirst++) {
    ib_data[iafirst] = static_cast<int8_T>(ib_data[iafirst]);
  }
  *ib_size = nia + 1;
  if (nc + 1 < 1) {
    c_size[1] = 0;
  } else {
    c_size[1] = nc + 1;
  }
}

void do_vectors(const emlrtStack *sp, const real_T a_data[],
                const int32_T a_size[2], const real_T b_data[],
                const int32_T b_size[2], real_T c_data[], int32_T c_size[2],
                int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
                int32_T *ib_size)
{
  int32_T iafirst;
  int32_T ialast;
  int32_T ibfirst;
  int32_T iblast;
  int32_T na;
  int32_T nb;
  int32_T nc;
  int32_T ncmax;
  na = a_size[1];
  nb = b_size[1];
  ncmax = muIntScalarMin_sint32(a_size[1], b_size[1]);
  c_size[0] = 1;
  c_size[1] = ncmax;
  *ia_size = ncmax;
  *ib_size = ncmax;
  if (!issorted(a_data, a_size)) {
    emlrtErrorWithMessageIdR2018a(sp, &c_emlrtRTEI,
                                  "Coder:toolbox:eml_setop_unsortedA",
                                  "Coder:toolbox:eml_setop_unsortedA", 0);
  }
  if (!issorted(b_data, b_size)) {
    emlrtErrorWithMessageIdR2018a(sp, &b_emlrtRTEI,
                                  "Coder:toolbox:eml_setop_unsortedB",
                                  "Coder:toolbox:eml_setop_unsortedB", 0);
  }
  nc = 0;
  iafirst = 0;
  ialast = 1;
  ibfirst = 0;
  iblast = 1;
  while ((ialast <= na) && (iblast <= nb)) {
    real_T ak;
    real_T bk;
    int32_T b_ialast;
    int32_T b_iblast;
    b_ialast = ialast;
    ak = a_data[ialast - 1];
    while ((b_ialast < a_size[1]) && (a_data[b_ialast] == ak)) {
      b_ialast++;
    }
    ialast = b_ialast;
    b_iblast = iblast;
    bk = b_data[iblast - 1];
    while ((b_iblast < b_size[1]) && (b_data[b_iblast] == bk)) {
      b_iblast++;
    }
    iblast = b_iblast;
    if (ak == bk) {
      nc++;
      c_data[nc - 1] = ak;
      ia_data[nc - 1] = iafirst + 1;
      ib_data[nc - 1] = ibfirst + 1;
      ialast = b_ialast + 1;
      iafirst = b_ialast;
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    } else {
      boolean_T p;
      if (muDoubleScalarIsNaN(bk)) {
        p = !muDoubleScalarIsNaN(ak);
      } else if (muDoubleScalarIsNaN(ak)) {
        p = false;
      } else {
        p = (ak < bk);
      }
      if (p) {
        ialast = b_ialast + 1;
        iafirst = b_ialast;
      } else {
        iblast = b_iblast + 1;
        ibfirst = b_iblast;
      }
    }
  }
  if (ncmax > 0) {
    if (nc > ncmax) {
      emlrtErrorWithMessageIdR2018a(sp, &e_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nc < 1) {
      *ia_size = 0;
    } else {
      *ia_size = nc;
    }
    if (nc > ncmax) {
      emlrtErrorWithMessageIdR2018a(sp, &f_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nc < 1) {
      *ib_size = 0;
    } else {
      *ib_size = nc;
    }
    if (nc > ncmax) {
      emlrtErrorWithMessageIdR2018a(sp, &g_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nc < 1) {
      c_size[1] = 0;
    } else {
      c_size[1] = nc;
    }
  }
}

} // namespace coder

// End of code generation (eml_setop.cpp)
