<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("utf-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<link rel="stylesheet" href="../css/style.css">
<link href="https://fonts.googleapis.com/css2?family=Praise&display=swap" rel="stylesheet">
<link href="https://fonts.googleapis.com/css2?family=Nanum+Gothic&display=swap" rel="stylesheet">
<link href="https://fonts.googleapis.com/css2?family=Gugi&display=swap" rel="stylesheet">
<title>로그인 여부 확인</title>
<script src="https://kit.fontawesome.com/1b5a5bad3c.js" crossorigin="anonymous"></script>
<script defer src="../js/site.js"></script>
<jsp:useBean id="dto" class="customer.CustomerDTO" scope="session"/>
</head>
<body>
<%
boolean flag = dto.isVerified();
if(flag) {
	response.sendRedirect("./pwCheck.jsp");
} else {
%>
<div class="main">
    <nav>
      <div class="search">
        <input type="text" class="search_insert" placeholder="검색">
        <i class="fas fa-search"></i>
      </div>
      <div class="radio">
        <input type="radio" id="tab1" name="tab" checked>
        <label for="tab1" class="tabMenu">카테고리</label>
        <input type="radio" id="tab2" name="tab">
        <label for="tab2" class="tabMenu"> 게시판</label>
        <div class="category">
          <ul>
            <li><a href="#">상의</a></li>
            <li><a href="#">아우터</a></li>
            <li><a href="#">팬츠</a></li>
            <li><a href="#">셔츠/블라우스</a></li>
            <li><a href="#">원피스</a></li>
            <li><a href="#">스커트</a></li>
          </ul>
        </div>
        <div class="board">
          <ul>
            <li><a href="#">공지사항</a></li>
            <li><a href="#">문의게시판</a></li>
            <li><a href="#">리뷰</a></li>
          </ul>
        </div>
      </div>
    </nav>
    <div class="main_contents">
      <header>
        <div class="main_logo"><a href="index.html">HyeJung</a></div>
      </header>
      <div class="section">
        <section>
          <div class="new">
            <div class="new_logo">
              <span>신상템</span>
            </div>
            <div class="new_preview">
              <div class="new_contents">
                <div class="img">
                </div>
                <span><a href="#">신상템1</a></span>
              </div>
              <div class="new_contents">
                <div class="img">
                </div>
                <span><a href="#">신상템2</a></span>
              </div>
              <div class="new_contents">
                <div class="img">
                </div>
                <span><a href="#">신상템3</a></span>
              </div>
              <div class="new_contents">
                <div class="img">
                </div>
                <span><a href="#">신상템4</a></span>
              </div>
              <div class="new_contents">
                <div class="img">
                </div>
                <span><a href="#">신상템5</a></span>
              </div>
              <div class="new_contents">
                <div class="img">
                </div>
                <span><a href="#">신상템6</a></span>
              </div>
            </div>
          </div>
          <div class="best">
            <div class="best_logo">
              <span>베스트 아이템</span>
            </div>
            <div class="best_preview">
              <div class="best_contents">
                <div class="img">
                </div>
                <span><a href="#">베스트 아이템1</a></span>
              </div>
              <div class="best_contents">
                <div class="img">
                </div>
                <span><a href="#">베스트 아이템2</a></span>
              </div>
              <div class="best_contents">
                <div class="img">
                </div>
                <span><a href="#">베스트 아이템3</a></span>
              </div>
              <div class="best_contents">
                <div class="img">
                </div>
                <span><a href="#">베스트 아이템4</a></span>
              </div>
              <div class="best_contents">
                <div class="img">
                </div>
                <span><a href="#">베스트 아이템5</a></span>
              </div>
              <div class="best_contents">
                <div class="img">
                </div>
                <span><a href="#">베스트 아이템6</a></span>
              </div>
            </div>
          </div>
        </section>
      </div>
    </div>
  </div>
  <div class="sideBar">
    <div class="button">
      <i class="fas fa-long-arrow-alt-left"></i>
    </div>
    <div class="info">
      <div class="login">
        <span class="singIn"><a href="login.html">로그인</a></span>
        <span class="create"><a href="join.html">회원가입</a></span>
      </div>
      <div class="my">
        <div class="myPage">
          <i class="fas fa-user"></i>
          <span><a href="./jsp/infoModi_check.jsp">정보 수정</a></span>
        </div>
        <div class="cart">
          <i class="fas fa-shopping-cart"></i>
          <span><a href="#">장바구니</a></span>
        </div>
      </div>
      <div class="order">
        <a href="#"><i class="fas fa-clipboard-list"></i></a>
        <span><a href="#">주문조회</a></span>
      </div>
    </div>
  </div>
<script>alert("로그인 후 이용가능합니다."); location.href="../index.html";</script>
<% } %>
</body>
</html>
