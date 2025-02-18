Title: E听说答案获取器（2024年10月）
Date: 2025-02-16 18:04:29
Category: tool
<!-- Tags: <TAG1>,<TAG2> -->
<!-- Slug: ansget
Author: zyc2024 -->
<!-- Summary: <SUMMARY> -->

<!-- <PASSAGE> -->

简介：给E听说的题目获取答案，妈妈再也不用担心我看不见“answer”了！

使用步骤：

1. 打开“C:/Users/[username]/AppData/Roaming/”

2. 在此文件夹下找一个很长的类似于“ACFE3D705F74656D705F74656D705F74002”的文件夹，并打开一个最新的（修改时间最晚的）类似于“200001”的文件夹。

3. 找到类似于“contentxxx001”的文件夹（从1开始），并打开里面的第一个JSON文件。

4. 你应该知道干什么了。

<input id="ets"></input>
<button onclick='javascript:t(document.getElementById("ets").value);'>Get!</button>
<h3 id="tj"></h3>

<script lang="text/javascript">
    function t(d) {
        c = JSON.parse(d);
        if (c.info.xtlist[1] != undefined) {
            a(c.info.xtlist[0].answer + c.info.xtlist[1].answer);
        }
        else if (c.info.xtlist[0] != undefined) {
            a(c.info.xtlist[0].answer);
        }
        else {
            alert("ERROR!!!")
        }
    }
    function a(d) {
        document.getElementById("tj").innerText = ("The answer is " + d + " !");
    }
</script>
