#include"parse.h"

int stmtSingle() {
  if(expr() < -1) return 0;

  expThisCh(';');
  return 1;
}

int stmtMulti() {
  if(!thisCh('{')) return 0;

  while(!thisCh('}')) expStmt();
  return 1;
}

int stmtDecl() {
  int ty = type();
  if(!ty) return 0;

  char* buf = getCursor();
  int len = expIdent();
  if(thisCh('[')) {
    int c = expNum();
    if(thisCh('+')) c += expNum();
    expThisCh(']');
    int array = defArray(buf, len, ty, c);
    if(thisCh('=')) {
      expThisCh('{');
      int d = 0;
      while(d < c) {
        int elem = expExpr();
        binOp(OP_ASG, arrayElem(array, constNum(TY_I64, d)), elem);
        d++;
        if(d != c) expThisCh(',');
      }
      expThisCh('}');
    }
  } else {
    int var = defVar(buf, len, ty);
    if(thisCh('=')) {
      int val = expExpr();
      binOp(OP_ASG, var, val);
    }
  }

  expThisCh(';');
  return 1;
}

int stmtRet() {
  if(!thisIdent("return")) return 0;

  int var;
  if(retTy() == TY_VOID) {
    var = VAR_VOID;
  } else {
    var = expExpr();
  }

  expThisCh(';');
  ret(var);
  return 1;
}

int stmtIf() {
  if(!thisIdent("if")) return 0;

  expThisCh('(');
  int var = expExpr();
  expThisCh(')');

  int id = ifBegin(var);
  expStmt();

  ifElse(id);
  if(thisIdent("else")) expStmt();

  ifEnd(id);

  return 1;
}

int stmtWhile() {
  if(!thisIdent("while")) return 0;

  int id = whileBegin();

  expThisCh('(');
  int var = expExpr();
  expThisCh(')');
  whileEval(id, var);

  expStmt();
  whileEnd(id);

  return 1;
}

int stmt() {
  if(stmtMulti()) return 1;
  if(stmtDecl()) return 1;
  if(stmtRet()) return 1;
  if(stmtIf()) return 1;
  if(stmtWhile()) return 1;
  return stmtSingle();
}


void expStmt() {
  if(!stmt()) {
    panicParse("stmt");
  }
}
