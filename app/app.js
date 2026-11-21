(() => {
  'use strict';

  const $ = (selector, context = document) => context.querySelector(selector);
  const $$ = (selector, context = document) => Array.from(context.querySelectorAll(selector));

  const icon = (name, extra = '') => `<svg class="icon ${extra}" aria-hidden="true"><use href="#i-${name}"/></svg>`;

  const escapeHTML = (value = '') => String(value)
    .replace(/&/g, '&amp;')
    .replace(/</g, '&lt;')
    .replace(/>/g, '&gt;')
    .replace(/"/g, '&quot;')
    .replace(/'/g, '&#039;');

  const formatMoney = (value) => Number(value || 0).toLocaleString('zh-CN', {
    minimumFractionDigits: 2,
    maximumFractionDigits: 2
  });

  const pageTitles = {
    dashboard: '工作台',
    jobs: '岗位样本',
    merchant: '商家自检',
    profile: '个人画像',
    wallet: '薪资存证',
    compliance: '合规检测',
    rights: '快捷维权',
    relief: '被骗救济',
    rules: '规则库',
    business: '合作模式',
    record: '记录详情'
  };

  const AI_CONFIG = {
    endpoint: 'https://api.deepseek.com/chat/completions',
    model: 'deepseek-chat'
  };

  const CLOCK_RATE = 30;
  const CLOCK_KEY = 'qxs_clock_v1';
  const WALLET_KEY = 'qxs_wallet_v1';
  const clock = { running: false, startAt: 0, finishedMs: 0, timer: null };

  const jobs = [
    {
      id: 'job-9',
      title: '线上刷单返利',
      merchant: '速赚联盟',
      category: '线上兼职',
      pay: '300',
      unit: '元/单',
      paySort: 300,
      settlement: '日结',
      location: '线上 · 群聊',
      area: '线上',
      distance: '远程沟通',
      schedule: '时间不限 · 按单结算',
      tags: ['高薪日结', '轻松操作', '手机可做'],
      description: '客服称在指定平台垫付购买商品，完成后返还本金并支付 8%-15% 佣金。前期小额任务会正常返款，后续要求连续做大额任务，否则前期本金无法退回。',
      requirements: ['需先垫付商品本金', '按客服指令下载指定 App', '不得向同学透露任务细节'],
      highlight: '高危样本 · 典型刷单返利骗局'
    },
    {
      id: 'job-10',
      title: '配音培训包接单',
      merchant: '声创未来学院',
      category: '教育培训',
      pay: '0',
      unit: '元/单',
      paySort: 0,
      settlement: '培训后结算',
      location: '济南 · 历下',
      area: '历下',
      distance: '距你 3.1km',
      schedule: '先培训 4 周 · 承诺包接单',
      tags: ['零基础', '包就业', '可分期'],
      description: '机构承诺零基础学习配音，毕业后包接单、月入过万。面试后要求通过合作平台办理 6,980 元培训分期，并称可从后续接单收入中扣除。',
      requirements: ['先办理培训分期', '完成 4 周课程', '接受机构统一安排接单'],
      highlight: '高危样本 · 培训贷与虚假就业承诺'
    },
    {
      id: 'job-11',
      title: '名企内推文员',
      merchant: '众合人力资源',
      category: '中介服务',
      pay: '280',
      unit: '元/天',
      paySort: 280,
      settlement: '日结',
      location: '济南 · 槐荫',
      area: '槐荫',
      distance: '写字楼面试',
      schedule: '面试后立即上岗',
      tags: ['名企直签', '高薪文员', '名额有限'],
      description: '中介称缴纳 399 元内推服务费即可安排名企文员岗位。面试后发现实际为外包客服，工作地点与薪资均与承诺不一致，服务费不予退还。',
      requirements: ['先缴纳内推服务费', '接受岗位调剂', '不签订书面协议'],
      highlight: '高危样本 · 中介收费与岗位货不对板'
    },
    {
      id: 'job-1',
      title: '周末咖啡店店员',
      merchant: 'M Stand 咖啡',
      category: '门店服务',
      pay: '200',
      unit: '元/天',
      paySort: 200,
      settlement: '日结',
      location: '济南 · 历下',
      area: '历下',
      distance: '距你 2.4km',
      schedule: '周六日 10:00-18:00',
      tags: ['包午餐', '地铁周边', '可连做'],
      description: '负责门店点单、饮品制作辅助、取餐区整理与顾客接待。门店氛围轻松，提供完整岗前培训，无需咖啡经验。',
      requirements: ['有服务意识，沟通自然', '可连续工作 4 个周末', '持健康证或可在入职前办理'],
      highlight: '商家已提交认证材料 · 薪资约定可存证'
    },
    {
      id: 'job-2',
      title: '校园新媒体运营',
      merchant: '知行教育工作室',
      category: '内容创作',
      pay: '150',
      unit: '元/天',
      paySort: 150,
      settlement: '周结',
      location: '线上 · 远程',
      area: '线上',
      distance: '远程办公',
      schedule: '每周 3 天 · 时间灵活',
      tags: ['远程', '作品集加分', '长期'],
      description: '运营校园新媒体账号，完成选题策划、图文编辑与社群互动。每周提交内容排期，数据表现优秀另有奖励。',
      requirements: ['熟悉小红书 / 公众号内容生态', '具备基础图片编辑能力', '每周可投入 12 小时以上'],
      highlight: '线上签约 · 周结金额可记录存证'
    },
    {
      id: 'job-3',
      title: '展会双语引导',
      merchant: '山东澜图会展',
      category: '活动执行',
      pay: '260',
      unit: '元/天',
      paySort: 260,
      settlement: '日结',
      location: '济南 · 山东国际会展中心',
      area: '槐荫',
      distance: '地铁直达会展中心',
      schedule: '11 月 12 日-14 日 08:30-17:30',
      tags: ['英语口语', '提供工作餐', '三天连做'],
      description: '负责展会入口引导、嘉宾接待与双语咨询，协助现场秩序维护。活动前提供统一培训与工作证件。',
      requirements: ['英语口语流利，CET-6 优先', '形象大方，有展会经验优先', '可完成三天连续工作'],
      highlight: '活动信息样本 · 结算条款待核验'
    },
    {
      id: 'job-4',
      title: '数据标注实习生',
      merchant: '云粒科技',
      category: '线上兼职',
      pay: '30',
      unit: '元/小时',
      paySort: 30,
      settlement: '月结',
      location: '线上 · 远程',
      area: '线上',
      distance: '远程办公',
      schedule: '每周 10-15 小时 · 自由排班',
      tags: ['远程', '技能培训', '实习证明'],
      description: '根据标注规范完成图像与文本数据整理，协助质检样本。任务按批次发放，提供线上培训与答疑支持。',
      requirements: ['耐心细致，能长期参与', '自备电脑与稳定网络', '每周至少完成 10 小时'],
      highlight: '企业已提交认证材料 · 金额与结算方式待确认'
    },
    {
      id: 'job-5',
      title: '晚托班辅导老师',
      merchant: '小树成长中心',
      category: '教育培训',
      pay: '80',
      unit: '元/小时',
      paySort: 80,
      settlement: '周结',
      location: '济南 · 高新区',
      area: '高新区',
      distance: '距你 5.1km',
      schedule: '工作日 16:30-19:30',
      tags: ['师范优先', '周结', '提供晚餐'],
      description: '辅导小学阶段学生完成课后作业，维持课堂秩序，并与家长进行简单反馈。每班不超过 8 名学生。',
      requirements: ['本科在读，师范专业优先', '有耐心，善于与孩子沟通', '每周至少到岗 3 天'],
      highlight: '办学材料已提交 · 认证仅为形式核验'
    },
    {
      id: 'job-6',
      title: '宠物店周末助理',
      merchant: '毛球研究所',
      category: '门店服务',
      pay: '180',
      unit: '元/天',
      paySort: 180,
      settlement: '日结',
      location: '济南 · 槐荫',
      area: '槐荫',
      distance: '距你 4.8km',
      schedule: '周六日 11:00-19:00',
      tags: ['宠物友好', '日结', '可撸猫'],
      description: '协助完成宠物洗护区清理、用品整理与顾客接待，不涉及专业洗护操作。店内有猫，需对宠物毛发不过敏。',
      requirements: ['喜欢小动物，不怕猫狗', '可接受站立工作', '周末可稳定到岗'],
      highlight: '工时记录可留痕 · 结算条款待确认'
    },
    {
      id: 'job-7',
      title: '短视频剪辑',
      merchant: '野芒内容实验室',
      category: '内容创作',
      pay: '300',
      unit: '元/条',
      paySort: 300,
      settlement: '项目结',
      location: '线上 · 远程',
      area: '线上',
      distance: '远程办公',
      schedule: '按项目交付 · 时间自由',
      tags: ['远程', '按条结算', '可长期合作'],
      description: '根据脚本完成 60 秒以内短视频剪辑，包含基础字幕、节奏卡点与封面制作。试稿通过后进入长期合作池。',
      requirements: ['熟练使用剪映 / PR', '有短视频作品可展示', '能在约定时间内交付'],
      highlight: '项目合同 · 验收后按约定记录结算'
    },
    {
      id: 'job-8',
      title: '超市理货员',
      merchant: '邻家生活超市',
      category: '门店服务',
      pay: '22',
      unit: '元/小时',
      paySort: 22,
      settlement: '日结',
      location: '济南 · 长清大学城',
      area: '长清',
      distance: '距你 3.2km',
      schedule: '可排班 · 每次 4 小时起',
      tags: ['排班灵活', '就近安排', '日结'],
      description: '负责货架商品整理、价签核对与简单库存盘点，协助高峰时段的顾客引导。工作强度适中。',
      requirements: ['认真负责，能接受站立工作', '每周可排班 2 次以上', '可长期兼职优先'],
      highlight: '门店用工样本 · 工时记录可留痕'
    }
  ];

  const sampleRisks = {
    'job-9': [
      { level: 'high', label: '要求垫付本金' },
      { level: 'high', label: '承诺高额返利' },
      { level: 'high', label: '诱导下载陌生 App' }
    ],
    'job-10': [
      { level: 'high', label: '诱导办理培训贷' },
      { level: 'high', label: '承诺包就业接单' },
      { level: 'high', label: '退费条件模糊' }
    ],
    'job-11': [
      { level: 'high', label: '先收中介服务费' },
      { level: 'high', label: '岗位信息与实际不符' },
      { level: 'high', label: '不提供书面协议' }
    ],
    'job-1': [
      { level: 'high', label: '薪资条款缺失' },
      { level: 'medium', label: '无书面合同' }
    ],
    'job-2': [
      { level: 'medium', label: '结算周期不明确' },
      { level: 'medium', label: '知识产权归属缺失' }
    ],
    'job-3': [
      { level: 'high', label: '无书面协议' },
      { level: 'medium', label: '超时补偿不明' }
    ],
    'job-4': [
      { level: 'high', label: '薪资计算口径不清' },
      { level: 'medium', label: '验收标准缺失' }
    ],
    'job-5': [
      { level: 'medium', label: '安全保障未约定' },
      { level: 'medium', label: '试用期待遇缺失' }
    ],
    'job-6': [
      { level: 'high', label: '意外责任未约定' },
      { level: 'medium', label: '无书面合同' }
    ],
    'job-7': [
      { level: 'medium', label: '验收标准不明确' },
      { level: 'medium', label: '版权归属不清' }
    ],
    'job-8': [
      { level: 'medium', label: '工时记录方式不明' },
      { level: 'medium', label: '休息时间未列明' }
    ]
  };

  const sampleMeta = {
    'job-9': { logo: '赚', logoClass: 'logo-coral' },
    'job-10': { logo: '声', logoClass: 'logo-purple' },
    'job-11': { logo: '众', logoClass: 'logo-sand' },
    'job-1': { logo: 'M', logoClass: 'logo-mstand' },
    'job-2': { logo: '知', logoClass: 'logo-blue' },
    'job-3': { logo: '澜', logoClass: 'logo-coral' },
    'job-4': { logo: '云', logoClass: 'logo-purple' },
    'job-5': { logo: '树', logoClass: 'logo-sand' },
    'job-6': { logo: '毛', logoClass: 'logo-coral' },
    'job-7': { logo: '野', logoClass: 'logo-purple' },
    'job-8': { logo: '邻', logoClass: 'logo-blue' }
  };

  jobs.forEach((job, index) => {
    Object.assign(job, sampleMeta[job.id] || {});
    job.risks = sampleRisks[job.id] || [];
    job.detected = `10 月 ${18 - Math.floor(index / 2)} 日`;
  });

  const initialTransactions = [
    { type: 'in', title: '校园新媒体运营 · 周结', meta: '10 月 18 日 14:32 · 双方确认已线下结算', amount: 450, status: '已确认' },
    { type: 'in', title: 'M Stand 咖啡 · 日结', meta: '10 月 17 日 19:05 · 双方确认已线下结算', amount: 200, status: '已确认' },
    { type: 'in', title: '展会双语引导 · 日结', meta: '10 月 12 日 18:40 · 双方确认已线下结算', amount: 520, status: '已确认' },
    { type: 'in', title: '宠物店周末助理 · 日结', meta: '10 月 11 日 20:10 · 双方确认已线下结算', amount: 180, status: '已确认' },
    { type: 'in', title: '短视频剪辑 · 项目结', meta: '10 月 9 日 09:30 · 验收记录已存证', amount: 300, status: '待确认' },
    { type: 'in', title: '超市理货员 · 日结', meta: '10 月 8 日 20:15 · 待商家确认结算', amount: 88, status: '待结算' }
  ];

  const initialMerchantJobs = [
    { id: 'pos-1', title: '周末咖啡店店员', meta: '济南 · 历下 · 周六日', pay: '200 元/天', settlement: '日结', riskCount: 2, status: 'active', logo: 'M', logoClass: 'logo-mstand' },
    { id: 'pos-2', title: '品牌快闪店店员', meta: '济南 · 槐荫 · 11 月档期', pay: '260 元/天', settlement: '日结', riskCount: 1, status: 'active', logo: 'M', logoClass: 'logo-mstand' },
    { id: 'pos-3', title: '咖啡师学徒', meta: '济南 · 历下 · 每周 3 天', pay: '30 元/小时', settlement: '周结', riskCount: 2, status: 'pending', logo: 'M', logoClass: 'logo-mstand' },
    { id: 'pos-4', title: '门店社群运营', meta: '线上 · 每周 8 小时', pay: '120 元/天', settlement: '周结', riskCount: 0, status: 'active', logo: 'M', logoClass: 'logo-mstand' },
    { id: 'pos-5', title: '秋季校园大使', meta: '多校区 · 项目制', pay: '150 元/天', settlement: '项目结', riskCount: 1, status: 'closed', logo: 'M', logoClass: 'logo-mstand' }
  ];

  const initialReliefHistory = [
    {
      id: 'AJ202609280126',
      type: '押金 / 保证金诈骗',
      amount: '¥199.00',
      status: '展示样例',
      date: '2026-09-28',
      name: '马小满',
      school: '山东大学',
      phone: '138****6621',
      merchant: '济南某咖啡店（个人微信收款）',
      payment: '微信转账',
      police: '未报警',
      detail: '在校园群看到「周末咖啡店兼职」信息，对方要求先交 199 元服装押金，承诺入职当天退还。转账后对方以「排班还没确认」为由拖延，随后不再回复消息，岗位信息也被删除。',
      files: ['聊天记录截图 · 5 张', '微信转账凭证 · 1 张', '岗位信息截图 · 2 张'],
      timeline: [
        { state: 'done', title: '展示样例已生成', note: '9 月 28 日 20:16' },
        { state: 'active', title: '公共维权渠道待使用', note: '请拨打 110 / 12315 / 12333' },
        { state: '', title: '公益资源对接', note: '规划中，当前不提供真实援助' },
        { state: '', title: '处理完成', note: '以真实渠道处理结果为准' }
      ],
      messages: [
        { who: '展示提示', text: '这是一条展示用沟通记录。当前版本不提供真实援助顾问服务，遇到诈骗请优先拨打 110 或 96110。', time: '9 月 29 日 10:05' },
        { who: '我', text: '好的，我会保留原始聊天记录和转账凭证。', time: '9 月 29 日 10:21' }
      ]
    }
  ];

  const defaultRightsCase = {
    id: 'WQ20261018032',
    type: '虚假岗位信息',
    amount: '¥300.00',
    date: '2026-10-18',
    submittedAt: '2026-10-18 14:20',
    status: '展示样例',
    merchant: '星启文化传媒有限公司',
    phone: '138****6621',
    detail: '10 月 17 日在兼职群看到「校园活动执行」岗位，对方承诺日结 300 元，要求先交 300 元「物料押金」。转账后对方以活动延期为由推脱，次日发现已被拉黑，岗位信息也已删除。',
    files: ['聊天记录截图 · 6 张', '转账凭证 · 1 张', '岗位信息截图 · 2 张'],
    timeline: [
      { state: 'done', title: '示例工单已生成', note: '10 月 18 日 14:20' },
      { state: 'done', title: '材料清单已展示', note: '10 月 18 日 16:05' },
      { state: 'active', title: '公共维权渠道待使用', note: '请拨打 12315 / 12333' },
      { state: '', title: '处理完成', note: '以真实渠道处理结果为准' }
    ],
    handler: { name: '平台规则小组', meta: '展示样例 · 非真实调解人员', avatar: '盾' },
    messages: [
      { who: '展示提示', text: '这是一条展示用沟通记录。当前版本不提供真实平台调解，遇到权益受损请优先拨打 12315 或 12333。', time: '10 月 18 日 16:10' },
      { who: '我', text: '好的，如果需要补充聊天记录我随时上传。', time: '10 月 18 日 16:24' }
    ]
  };

  const state = {
    category: '全部',
    search: '',
    location: 'all',
    sort: 'recommend',
    walletBalance: 1840,
    transactions: initialTransactions.slice(),
    merchantJobs: initialMerchantJobs.slice(),
    reliefHistory: initialReliefHistory.slice(),
    rightsCase: defaultRightsCase,
    reliefStep: 1,
    recordReturn: 'rights',
    recordNav: 'rights',
    scanTimers: [],
    scanning: false,
    aiApiKey: ''
  };

  function showToast(message, kind = 'success') {
    const container = $('#toastContainer');
    if (!container) return;
    const toast = document.createElement('div');
    toast.className = 'toast';
    toast.innerHTML = `${icon(kind === 'error' ? 'alert' : kind === 'info' ? 'info' : 'check-circle')}<span>${escapeHTML(message)}</span>`;
    container.appendChild(toast);
    window.setTimeout(() => {
      toast.classList.add('leaving');
      window.setTimeout(() => toast.remove(), 300);
    }, 3200);
  }

  function renderJobCard(job) {
    const highCount = job.risks.filter((risk) => risk.level === 'high').length;
    return `
      <article class="job-card sample-card" data-job-id="${escapeHTML(job.id)}" tabindex="0" role="button" aria-label="查看岗位风险样本：${escapeHTML(job.title)}">
        <div class="job-card-head">
          <div class="merchant-line">
            <span class="merchant-logo ${escapeHTML(job.logoClass || '')}">${escapeHTML(job.logo || job.merchant.slice(0, 1))}</span>
            <div>
              <strong>${escapeHTML(job.merchant)}</strong>
              <span class="merchant-verified">${icon('file')}已提交材料</span>
            </div>
          </div>
          <span class="sample-badge ${highCount >= 2 ? 'danger' : ''}">${highCount >= 2 ? '高危样本' : '待检岗位示例'}</span>
        </div>
        <div class="job-card-body">
          <div class="job-title-row">
            <h3>${escapeHTML(job.title)}</h3>
            <span class="sample-risk-count">风险项 ${job.risks.length} 个</span>
          </div>
          <div class="job-risk-chips">
            ${job.risks.map((risk) => `<span class="risk-chip ${risk.level}"><i></i>${escapeHTML(risk.label)}</span>`).join('')}
          </div>
        </div>
        <div class="job-meta">
          <span>${icon('map-pin')}${escapeHTML(job.location)}</span>
          <span>${icon('file')}检测于 ${escapeHTML(job.detected)}</span>
        </div>
        <div class="job-card-foot">
          <span class="sample-footnote">${highCount ? `${highCount} 项高风险提示` : '暂无高风险提示'} · 仅展示检测结果</span>
          <span class="sample-report-link">查看风险报告 ${icon('arrow-right')}</span>
        </div>
      </article>
    `;
  }

  function filteredJobs() {
    let list = jobs.filter((job) => {
      const keyword = state.search.trim().toLowerCase();
      const matchesKeyword = !keyword || [job.title, job.merchant, job.category, job.location, job.description, ...job.tags, ...job.risks.map((risk) => risk.label)]
        .join(' ')
        .toLowerCase()
        .includes(keyword);
      const matchesCategory = state.category === '全部' || job.category === state.category;
      const matchesLocation = state.location === 'all' || job.area === state.location;
      return matchesKeyword && matchesCategory && matchesLocation;
    });

    if (state.sort === 'risk') {
      const highRiskCount = (job) => job.risks.filter((risk) => risk.level === 'high').length;
      list = list.slice().sort((a, b) => highRiskCount(b) - highRiskCount(a) || b.risks.length - a.risks.length);
    }
    return list;
  }

  function renderJobGrids() {
    const homeGrid = $('#homeJobGrid');
    const jobGrid = $('#jobGrid');
    if (homeGrid) homeGrid.innerHTML = jobs.slice(0, 4).map(renderJobCard).join('');

    const list = filteredJobs();
    if (jobGrid) jobGrid.innerHTML = list.map(renderJobCard).join('');
    const count = $('#jobResultCount');
    if (count) count.textContent = String(list.length);
    const empty = $('#jobEmptyState');
    if (empty) empty.classList.toggle('visible', list.length === 0);
  }

  function openModal(id) {
    const modal = document.getElementById(id);
    if (!modal) return;
    modal.classList.add('open');
    document.body.style.overflow = 'hidden';
  }

  function closeModal(id) {
    const modal = document.getElementById(id);
    if (!modal) return;
    modal.classList.remove('open');
    if (!$('.modal-backdrop.open')) document.body.style.overflow = '';
  }

  function returnHome() {
    $$('.modal-backdrop.open').forEach((modal) => closeModal(modal.id));
    navigate('dashboard');
    window.scrollTo({ top: 0, behavior: 'smooth' });
  }

  function openJobModal(id) {
    const job = jobs.find((item) => item.id === id);
    if (!job) return;
    const content = $('#jobModalContent');
    content.innerHTML = `
      <div class="job-modal-head">
        <div class="job-modal-top">
          <span class="merchant-logo ${escapeHTML(job.logoClass || '')}">${escapeHTML(job.logo)}</span>
          <div class="job-modal-title">
            <div class="merchant-line">
              <div><strong>${escapeHTML(job.merchant)}</strong><span class="merchant-verified">${icon('file')}已提交认证材料</span></div>
            </div>
            <h2 id="jobModalTitle">${escapeHTML(job.title)}</h2>
            <div class="job-meta">
              <span>${icon('map-pin')}${escapeHTML(job.location)}</span>
              <span>${icon('file')}检测于 ${escapeHTML(job.detected)}</span>
              <span>${icon('alert')}风险项 ${job.risks.length} 个</span>
            </div>
          </div>
          <span class="sample-badge modal-sample-badge ${job.risks.filter((risk) => risk.level === 'high').length >= 2 ? 'danger' : ''}">${job.risks.filter((risk) => risk.level === 'high').length >= 2 ? '高危样本' : '待检岗位示例'}</span>
        </div>
        <div class="job-modal-badges">
          <span>${icon('file')}仅展示检测结果</span>
          <span>${icon('info')}不提供联系方式</span>
          <span>${icon('lock')}不提供报名或交易入口</span>
        </div>
        <p class="certification-boundary">认证说明：商家认证仅为提交材料的形式核验展示，不代表平台担保岗位真实可靠，请学生自行甄别风险。</p>
      </div>
      <div class="job-modal-body">
        <div>
          <section class="job-modal-section">
            <h3>样本岗位内容</h3>
            <p>${escapeHTML(job.description)}</p>
          </section>
          <section class="job-modal-section">
            <h3>样本中的约定要求</h3>
            <ul>${job.requirements.map((item) => `<li>${escapeHTML(item)}</li>`).join('')}</ul>
          </section>
          <section class="job-modal-section">
            <h3>检测出的风险项</h3>
            <div class="modal-risk-list">
              ${job.risks.map((risk) => `<div class="modal-risk-item ${risk.level}"><span>${risk.level === 'high' ? '高风险隐患' : '中等风险隐患'}</span><strong>${escapeHTML(risk.label)}</strong></div>`).join('')}
            </div>
          </section>
          <div class="sample-disclaimer-inline">
            ${icon('info')}
            <p>本样本仅用于展示岗位风险检测结果，不包含联系方式，也不提供报名、申请或交易入口。</p>
          </div>
        </div>
        <aside class="job-modal-side">
          <div class="job-safety-score">
            <div><span>样本说明</span><strong style="font-size:12px">仅展示检测结果</strong></div>
            <p>平台不对岗位真实性和可靠性作出担保，请自行核实工作内容与结算约定。</p>
          </div>
          <div class="job-safe-checks">
            <span>${icon('file')}商家认证材料仅作形式核验</span>
            <span>${icon('info')}样本不提供任何联系方式</span>
            <span>${icon('alert')}如遇类似风险可提交维权工单</span>
          </div>
          <button class="button button-dark" data-page="compliance">检测我的合同</button>
          <button class="button button-light" data-close-modal="jobModal">返回样本库</button>
          <button class="job-modal-footnote" style="background:none;border:0;padding:0;cursor:pointer;text-align:left" data-toast="如遇权益受损，请前往快捷维权提交工单">${icon('alert')}我有类似问题</button>
        </aside>
      </div>
    `;
    openModal('jobModal');
  }

  function navigate(page) {
    if (!pageTitles[page]) page = 'dashboard';
    if (location.hash === `#${page}`) {
      activatePage(page);
      window.scrollTo({ top: 0, behavior: 'smooth' });
    } else {
      location.hash = page;
    }
  }

  function activatePage(page) {
    if (!pageTitles[page]) page = 'dashboard';
    $$('.page').forEach((section) => section.classList.toggle('active', section.id === `page-${page}`));
    $$('.nav-item').forEach((item) => item.classList.toggle('active', item.dataset.page === page));
    if (page === 'record') {
      $$('.nav-item').forEach((item) => item.classList.toggle('active', item.dataset.page === state.recordNav));
      if (!$('#recordDetail')?.innerHTML.trim()) renderRightsRecord(state.rightsCase);
    }
    const title = $('#topbarTitle');
    if (title) title.textContent = pageTitles[page];
    document.title = `${pageTitles[page]} · 青薪盾`;
    closeSidebar();
    if (page === 'wallet') renderWallet();
    if (page === 'merchant') {
      renderMerchantJobs();
      switchMerchantTab($('.merchant-panel.active')?.id.replace('merchant-panel-', '') || 'publish');
    }
    if (page === 'relief') {
      resetReliefView();
      renderReliefHistory();
    }
    if (page === 'compliance') {
      window.setTimeout(() => {
        if (!$('#complianceGate')?.classList.contains('open')) openModal('complianceGate');
        $('#acceptComplianceGate')?.focus();
      }, 80);
    } else {
      closeModal('complianceGate');
    }
  }

  function openSidebar() {
    $('#sidebar').classList.add('open');
    $('#sidebarScrim').classList.add('visible');
  }

  function closeSidebar() {
    $('#sidebar').classList.remove('open');
    $('#sidebarScrim').classList.remove('visible');
  }

  function renderWallet() {
    const balanceEl = $('#walletBalance');
    const balanceText = formatMoney(state.walletBalance);
    if (balanceEl) balanceEl.textContent = balanceText;
    const list = $('#transactionList');
    if (list) {
      list.innerHTML = state.transactions.map((transaction) => `
        <div class="transaction-row">
          <span class="transaction-icon ${transaction.type === 'out' ? 'out' : ''}">${icon(transaction.type === 'out' ? 'arrow-up-right' : 'banknote')}</span>
          <div class="transaction-info"><strong>${escapeHTML(transaction.title)}</strong><span>${escapeHTML(transaction.meta)}</span></div>
          <div class="transaction-amount ${transaction.type === 'out' ? 'out' : ''}">${transaction.type === 'out' ? '-' : '+'}¥${formatMoney(transaction.amount)}<small>${transaction.status || '已确认'}</small></div>
        </div>
      `).join('');
    }
  }

  function saveWallet() {
    try {
      localStorage.setItem(WALLET_KEY, JSON.stringify({
        balance: state.walletBalance,
        transactions: state.transactions
      }));
    } catch (error) {
      /* 忽略隐私模式下的存储异常 */
    }
  }

  function restoreWallet() {
    try {
      const saved = JSON.parse(localStorage.getItem(WALLET_KEY) || 'null');
      if (saved && Array.isArray(saved.transactions) && saved.transactions.length) {
        state.transactions = saved.transactions;
        if (Number.isFinite(Number(saved.balance))) state.walletBalance = Number(saved.balance);
      }
    } catch (error) {
      /* 忽略损坏的本地记录 */
    }
    renderWallet();
  }

  function exportRecords() {
    const now = new Date();
    const stamp = `${now.getFullYear()}${String(now.getMonth() + 1).padStart(2, '0')}${String(now.getDate()).padStart(2, '0')}`;
    const rows = [['日期 / 记录', '说明', '收支', '金额（元）', '状态']];
    state.transactions.forEach((transaction) => {
      const [datePart, ...noteParts] = String(transaction.meta || '').split(' · ');
      rows.push([
        datePart || '',
        [transaction.title, ...noteParts].filter(Boolean).join(' · '),
        transaction.type === 'out' ? '支出' : '收入',
        formatMoney(transaction.amount),
        transaction.status || '已确认'
      ]);
    });
    rows.push(['合计', '当前存证金额', '收入', formatMoney(state.walletBalance), '']);

    const csv = '\uFEFF' + rows
      .map((row) => row.map((cell) => `"${String(cell).replace(/"/g, '""')}"`).join(','))
      .join('\r\n');
    const blob = new Blob([csv], { type: 'text/csv;charset=utf-8;' });
    const url = URL.createObjectURL(blob);
    const link = document.createElement('a');
    link.href = url;
    link.download = `青薪盾-薪资存证记录-${stamp}.csv`;
    document.body.appendChild(link);
    link.click();
    link.remove();
    window.setTimeout(() => URL.revokeObjectURL(url), 1500);
    showToast(`已导出 ${state.transactions.length} 条存证记录（CSV，可用 Excel 打开）`);
  }

  function formatDuration(ms) {
    const total = Math.max(0, Math.floor(ms / 1000));
    const hours = String(Math.floor(total / 3600)).padStart(2, '0');
    const minutes = String(Math.floor((total % 3600) / 60)).padStart(2, '0');
    const seconds = String(total % 60).padStart(2, '0');
    return `${hours}:${minutes}:${seconds}`;
  }

  function clockElapsed() {
    return clock.running ? Date.now() - clock.startAt : clock.finishedMs;
  }

  function saveClock() {
    try {
      localStorage.setItem(CLOCK_KEY, JSON.stringify(clock.running ? { running: true, startAt: clock.startAt } : { running: false }));
    } catch (error) {
      /* 忽略隐私模式下的存储异常 */
    }
  }

  function renderClock() {
    const clockCard = $('.clock-card');
    const display = $('#clockDisplay');
    const status = $('#clockStatusBadge');
    const button = $('#clockButton');
    const earning = $('#clockEarning');
    const hint = $('#clockHint');
    if (!display) return;
    const elapsed = clockElapsed();
    display.textContent = formatDuration(elapsed);
    if (earning) earning.textContent = `¥${formatMoney((elapsed / 3600000) * CLOCK_RATE)}`;
    clockCard?.classList.toggle('running', clock.running);
    if (clock.running) {
      if (status) status.innerHTML = '<span class="status-dot"></span>工作中';
      if (button) button.innerHTML = `${icon('check')}结束工作`;
      if (hint) hint.textContent = '计时中 · 按 ¥30/小时计算预计收入';
    } else {
      if (status) status.innerHTML = `<span class="status-dot"></span>${clock.finishedMs ? '已结束' : '未开始'}`;
      if (button) button.innerHTML = `${icon('clock')}开始工作`;
      if (hint) hint.textContent = clock.finishedMs ? '本次工时已记录，可开始新一次打卡' : '开始打卡后自动计算工时';
    }
  }

  function startClock() {
    if (clock.running) return;
    clock.running = true;
    clock.startAt = Date.now();
    clock.finishedMs = 0;
    saveClock();
    window.clearInterval(clock.timer);
    clock.timer = window.setInterval(renderClock, 1000);
    renderClock();
    showToast('已开始计时，结束工作时会自动写入存证记录');
  }

  function stopClock() {
    if (!clock.running) return;
    const elapsed = Date.now() - clock.startAt;
    clock.running = false;
    clock.finishedMs = elapsed;
    window.clearInterval(clock.timer);
    clock.timer = null;
    saveClock();
    if (elapsed >= 5000) {
      const amount = Math.round((elapsed / 3600000) * CLOCK_RATE * 100) / 100;
      const now = new Date();
      const dateText = `${now.getMonth() + 1} 月 ${now.getDate()} 日 ${String(now.getHours()).padStart(2, '0')}:${String(now.getMinutes()).padStart(2, '0')}`;
      state.transactions.unshift({
        type: 'in',
        title: 'M Stand 咖啡 · 工时打卡',
        meta: `${dateText} · 工时 ${formatDuration(elapsed)} · 待商家确认结算`,
        amount,
        status: '待确认'
      });
      state.walletBalance += amount;
      saveWallet();
      renderWallet();
      showToast(`本次工时 ${formatDuration(elapsed)}，预计收入 ¥${formatMoney(amount)} 已写入存证记录`);
    } else {
      showToast('本次打卡时间太短，未生成存证记录', 'info');
    }
    renderClock();
  }

  function resetClock() {
    window.clearInterval(clock.timer);
    clock.running = false;
    clock.timer = null;
    clock.startAt = 0;
    clock.finishedMs = 0;
    saveClock();
    renderClock();
    showToast('打卡记录已重置', 'info');
  }

  function restoreClock() {
    try {
      const saved = JSON.parse(localStorage.getItem(CLOCK_KEY) || 'null');
      if (saved?.running && Number(saved.startAt)) {
        clock.running = true;
        clock.startAt = Number(saved.startAt);
        clock.timer = window.setInterval(renderClock, 1000);
      }
    } catch (error) {
      /* 忽略损坏的本地记录 */
    }
    renderClock();
  }

  function switchMerchantTab(tab) {
    $$('#merchantTabs .tab').forEach((item) => item.classList.toggle('active', item.dataset.merchantTab === tab));
    $$('.merchant-panel').forEach((panel) => panel.classList.toggle('active', panel.id === `merchant-panel-${tab}`));
    if (tab === 'manage') renderMerchantJobs();
  }

  function renderMerchantJobs() {
    const list = $('#merchantJobList');
    if (list) {
      list.innerHTML = state.merchantJobs.map((position) => {
        const statusMap = {
          active: ['检测完成', ''],
          pending: ['检测中', 'pending'],
          closed: ['已归档', 'closed']
        };
        const [statusText, statusClass] = statusMap[position.status] || statusMap.active;
        return `
          <div class="merchant-job-row">
            <div class="merchant-job-info">
              <span class="merchant-logo ${escapeHTML(position.logoClass || 'logo-mstand')}">${escapeHTML(position.logo || 'M')}</span>
              <div><strong>${escapeHTML(position.title)}</strong><span>${escapeHTML(position.meta)}</span></div>
            </div>
            <div class="merchant-job-cell"><strong>${escapeHTML(position.pay)}</strong><span>${escapeHTML(position.settlement)}</span></div>
            <div class="merchant-job-cell"><strong>${position.riskCount || 0} 项</strong><span>风险提示</span></div>
            <div><span class="status-label ${statusClass}">${statusText}</span></div>
            <div class="row-actions">
              <button class="button button-light button-sm" data-toast="示例模式：检测报告暂不展开">查看报告</button>
            </div>
          </div>
        `;
      }).join('');
    }
    const count = $('#manageCount');
    if (count) count.textContent = String(state.merchantJobs.length);
  }

  function renderReliefHistory() {
    const list = $('#reliefHistoryList');
    if (!list) return;
    const history = state.reliefHistory;
    if (!Array.isArray(history) || !history.length) {
      list.innerHTML = '<p style="font-size:9px;color:#9ba59f">暂无申请记录</p>';
      return;
    }
    list.innerHTML = history.slice(0, 4).map((item) => `
      <button type="button" class="relief-history-item" data-open-record="relief" data-relief-id="${escapeHTML(item.id)}">
        <strong>${escapeHTML(item.id)}<span>${escapeHTML(item.status)}</span></strong>
        <p>${escapeHTML(item.type)} · ${escapeHTML(item.amount)}</p>
        <svg class="icon relief-history-arrow"><use href="#i-chevron-right"/></svg>
      </button>
    `).join('');
  }

  function timelineItemsHTML(items) {
    return items.map((item) => `
      <div class="timeline-item ${item.state || ''}">
        <span class="timeline-dot"></span>
        <div><strong>${escapeHTML(item.title)}</strong><small>${escapeHTML(item.note || '')}</small></div>
      </div>
    `).join('');
  }

  function recordTimelineHTML(items, compact = false) {
    return `<div class="timeline ${compact ? 'compact-timeline' : ''}">${timelineItemsHTML(items)}</div>`;
  }

  function recordFilesHTML(files) {
    return `<div class="record-files">${files.map((file) => `
      <div class="record-file">${icon('file')}<span>${escapeHTML(file)}</span></div>
    `).join('')}</div>`;
  }

  function recordMessagesHTML(messages) {
    return `<div class="record-messages">${messages.map((message) => `
      <div class="record-message">
        <span class="record-msg-avatar">${escapeHTML(message.who === '我' ? '我' : '盾')}</span>
        <div>
          <strong>${escapeHTML(message.who)}</strong>
          <p>${escapeHTML(message.text)}</p>
          <small>${escapeHTML(message.time)}</small>
        </div>
      </div>
    `).join('')}</div>`;
  }

  function renderRightsRecord(record) {
    const eyebrow = $('#recordEyebrow');
    const title = $('#recordTitle');
    const subtitle = $('#recordSubtitle');
    const badge = $('#recordStatusBadge');
    const container = $('#recordDetail');
    if (!container) return;
    if (eyebrow) eyebrow.textContent = 'CASE RECORD';
    if (title) title.textContent = '维权工单详情';
    if (subtitle) subtitle.textContent = '展示版工单详情：以下信息仅保存在当前页面，不代表真实平台调解受理。';
    if (badge) {
      badge.textContent = record.status;
      badge.className = `badge ${record.status === '处理完成' ? 'badge-green' : 'badge-sand'}`;
    }
    container.innerHTML = `
      <div class="record-grid">
        <div class="record-main">
          <section class="table-card record-card">
            <div class="record-summary">
              <div><span>工单编号</span><strong>${escapeHTML(record.id)}</strong></div>
              <div><span>维权类型</span><strong>${escapeHTML(record.type)}</strong></div>
              <div><span>涉及金额</span><strong>${escapeHTML(record.amount)}</strong></div>
              <div><span>提交时间</span><strong>${escapeHTML(record.submittedAt)}</strong></div>
            </div>
            <div class="record-block">
              <h3>事情经过</h3>
              <p>${escapeHTML(record.detail)}</p>
            </div>
            <div class="record-block">
              <div class="record-block-head"><h3>证据材料</h3><span>${record.files.length} 份 · 演示记录</span></div>
              ${recordFilesHTML(record.files)}
            </div>
            <div class="record-block">
              <h3>处理进度</h3>
              ${recordTimelineHTML(record.timeline)}
            </div>
            <div class="record-block">
              <h3>沟通记录</h3>
              ${recordMessagesHTML(record.messages)}
            </div>
            <div class="record-actions">
              <button type="button" class="button button-light" data-toast="补充材料入口已打开（展示版本）">${icon('upload')}补充证据</button>
              <button type="button" class="button button-dark" data-toast="已提醒调解员尽快跟进">${icon('message')}催促进度</button>
            </div>
          </section>
        </div>
        <aside class="record-side">
          <section class="aside-card">
            <div class="section-heading mini"><div><p class="eyebrow">HANDLER</p><h3>处理人</h3></div></div>
            <div class="record-handler">
              <span class="avatar avatar-lin">${escapeHTML(record.handler.avatar)}</span>
              <div><strong>${escapeHTML(record.handler.name)}</strong><small>${escapeHTML(record.handler.meta)}</small></div>
            </div>
            <div class="record-info-list">
              <div><span>当前状态</span><strong>${escapeHTML(record.status)}</strong></div>
              <div><span>涉事商家</span><strong>${escapeHTML(record.merchant)}</strong></div>
              <div><span>联系电话</span><strong>${escapeHTML(record.phone)}</strong></div>
              <div><span>调解服务</span><strong>规划中</strong></div>
            </div>
          </section>
          <section class="aside-card record-tip-card">
            <div class="section-heading mini"><div><p class="eyebrow">NEXT STEP</p><h3>下一步建议</h3></div></div>
            <ul class="check-list">
              <li><span>01</span>保留原始聊天记录与转账凭证</li>
              <li><span>02</span>展示版不会上传文件，请勿填写真实敏感信息</li>
              <li><span>03</span>紧急情况请拨打 110、12315 或 12333</li>
            </ul>
            <a class="button button-light button-block" href="https://www.12315.cn/" target="_blank" rel="noopener noreferrer">${icon('scale')}前往 12315 投诉</a>
          </section>
        </aside>
      </div>
    `;
  }

  function renderReliefRecord(record) {
    const eyebrow = $('#recordEyebrow');
    const title = $('#recordTitle');
    const subtitle = $('#recordSubtitle');
    const badge = $('#recordStatusBadge');
    const container = $('#recordDetail');
    if (!container) return;
    if (eyebrow) eyebrow.textContent = 'RELIEF RECORD';
    if (title) title.textContent = '救济申请详情';
    if (subtitle) subtitle.textContent = '展示版申请详情：以下信息仅保存在当前页面，不代表已获得真实外部援助。';
    if (badge) {
      badge.textContent = record.status;
      badge.className = `badge ${record.status === '援助中' ? 'badge-sand' : 'badge-green'}`;
    }
    container.innerHTML = `
      <div class="record-grid">
        <div class="record-main">
          <section class="table-card record-card">
            <div class="record-summary">
              <div><span>申请编号</span><strong>${escapeHTML(record.id)}</strong></div>
              <div><span>被骗类型</span><strong>${escapeHTML(record.type)}</strong></div>
              <div><span>被骗金额</span><strong>${escapeHTML(record.amount)}</strong></div>
              <div><span>提交日期</span><strong>${escapeHTML(record.date)}</strong></div>
            </div>
            <div class="record-block">
              <h3>申请人信息</h3>
              <div class="record-info-grid">
                <div><span>姓名</span><strong>${escapeHTML(record.name || '马小满')}</strong></div>
                <div><span>就读院校</span><strong>${escapeHTML(record.school || '山东大学')}</strong></div>
                <div><span>联系电话</span><strong>${escapeHTML(record.phone || '138****6621')}</strong></div>
                <div><span>支付方式</span><strong>${escapeHTML(record.payment || '微信转账')}</strong></div>
                <div><span>是否报警</span><strong>${escapeHTML(record.police || '未报警')}</strong></div>
                <div><span>涉事商家</span><strong>${escapeHTML(record.merchant || '未填写')}</strong></div>
              </div>
            </div>
            <div class="record-block">
              <h3>事件经过</h3>
              <p>${escapeHTML(record.detail)}</p>
            </div>
            <div class="record-block">
              <div class="record-block-head"><h3>已提交材料</h3><span>${record.files.length} 份 · 演示记录</span></div>
              ${recordFilesHTML(record.files)}
            </div>
            <div class="record-block">
              <h3>援助进度</h3>
              ${recordTimelineHTML(record.timeline)}
            </div>
            <div class="record-block">
              <h3>沟通记录</h3>
              ${recordMessagesHTML(record.messages)}
            </div>
            <div class="record-actions">
              <button type="button" class="button button-light" data-toast="补充材料入口已打开（展示版本）">${icon('upload')}补充材料</button>
              <button type="button" class="button button-dark" data-toast="请拨打 110、12315 或 12333 获取公共维权帮助">${icon('phone')}公共维权渠道</button>
            </div>
          </section>
        </div>
        <aside class="record-side">
          <section class="aside-card">
            <div class="section-heading mini"><div><p class="eyebrow">RESOURCE STATUS</p><h3>援助资源状态</h3></div></div>
            <div class="record-handler">
              <span class="avatar avatar-lin">盾</span>
              <div><strong>援助资源对接</strong><small>规划中 · 非真实援助顾问</small></div>
            </div>
            <div class="record-info-list">
              <div><span>资源状态</span><strong>规划中</strong></div>
              <div><span>公共渠道</span><strong>110 / 12315 / 12333</strong></div>
              <div><span>申请状态</span><strong>${escapeHTML(record.status)}</strong></div>
            </div>
          </section>
          <section class="aside-card record-tip-card">
            <div class="section-heading mini"><div><p class="eyebrow">NOTICE</p><h3>材料说明</h3></div></div>
            <p class="record-note">原始聊天记录和转账凭证请勿删除。截图仅作为辅助材料，原始记录更有法律效力。</p>
            <button type="button" class="button button-light button-block" data-toast="请拨打 110、12315 或 12333 获取公共维权帮助">${icon('phone')}公共维权渠道</button>
          </section>
        </aside>
      </div>
    `;
  }

  function openRecord(kind, id) {
    state.recordReturn = location.hash.replace('#', '') || 'rights';
    if (kind === 'relief') {
      const record = state.reliefHistory.find((item) => item.id === id) || state.reliefHistory[0];
      if (!record) {
        showToast('未找到申请记录', 'error');
        return;
      }
      state.recordNav = 'relief';
      renderReliefRecord(record);
    } else {
      state.recordNav = 'rights';
      renderRightsRecord(state.rightsCase);
    }
    navigate('record');
    window.scrollTo({ top: 0, behavior: 'smooth' });
  }

  const riskRules = [
    { key: 'fee', words: ['押金', '保证金', '服装费', '培训费', '平台费', '中介费', '先交', '先付', '垫付', '收费'], penalty: 35, label: '收费风险' },
    { key: 'gray', words: ['刷单', '冲销量', '返利', '高额返利', '代注册', '引流', '点赞赚钱', '跑分'], penalty: 45, label: '违规工作' },
    { key: 'promise', words: ['日入过万', '日入', '轻松月入', '月入过万', '躺赚', '无需经验', '动动手指'], penalty: 15, label: '虚假承诺' },
    { key: 'contact', words: ['加微信', '微信', 'QQ', '私聊', '私下交易'], penalty: 10, label: '私下联系' },
    { key: 'noContract', words: ['不签合同', '无需合同', '不签协议', '口头约定'], penalty: 18, label: '合同风险' },
    { key: 'vagueSalary', words: ['工资面议', '薪资面议', '待遇面议'], penalty: 10, label: '薪资模糊' },
    { key: 'sensitive', words: ['身份证', '银行卡', '验证码', '手持身份证'], penalty: 20, label: '信息风险' }
  ];

  function scanText(text) {
    let score = 100;
    const matched = {};
    const riskWords = new Set();
    riskRules.forEach((rule) => {
      const hits = rule.words.filter((word) => text.includes(word));
      if (hits.length) {
        matched[rule.key] = hits;
        hits.forEach((word) => riskWords.add(word));
        score -= rule.penalty;
      }
    });

    const hasAmount = /(?:¥|￥)?\s*\d+(?:\.\d+)?\s*元\s*(?:\/|每)?\s*(?:天|日|小时|月|条|次)/.test(text);
    const hasSettlement = /(日结|周结|月结|项目结|平台担保|担保结算)/.test(text);
    const hasContract = /(签订|签署|兼职协议|劳动合同|合同)/.test(text);
    const hasContent = /(工作内容|岗位职责|负责|主要工作)/.test(text);
    const hasSubject = /(公司|门店|工作室|企业|品牌|中心|咖啡馆|超市)/.test(text);

    if (!hasAmount) score -= 10;
    if (!hasSettlement) score -= 5;
    if (!hasContent) score -= 8;
    if (!hasContract && !matched.noContract) score -= 8;
    if (!hasSubject) score -= 5;
    score = Math.max(5, Math.min(100, score));

    const checks = [];
    if (matched.sensitive) {
      checks.push({ status: 'fail', name: '主体资质', detail: '岗位文本索取身份证、银行卡等敏感信息，存在身份盗用风险。' });
    } else if (hasSubject) {
      checks.push({ status: 'pass', name: '主体资质', detail: '识别到岗位主体信息，建议仍核验营业执照或门店地址。' });
    } else {
      checks.push({ status: 'warn', name: '主体资质', detail: '未识别到明确的岗位主体，无法确认发布方真实身份。' });
    }

    if (matched.promise || !hasAmount) {
      checks.push({ status: 'fail', name: '薪资规范', detail: matched.promise ? '出现「日入」「无需经验」等夸大承诺，薪资可信度低。' : '未识别到明确的薪资金额与计价单位，存在事后压价风险。' });
    } else if (!hasSettlement) {
      checks.push({ status: 'warn', name: '薪资规范', detail: '薪资金额明确，但未注明结算周期，建议事先确认支付时间。' });
    } else {
      checks.push({ status: 'pass', name: '薪资规范', detail: '薪资金额与结算方式清晰，符合平台信息规范。' });
    }

    if (matched.fee) {
      checks.push({ status: 'fail', name: '收费风险', detail: `检测到「${matched.fee.join('、')}」等收费表述。正规兼职不应向求职者收取任何费用。` });
    } else {
      checks.push({ status: 'pass', name: '收费风险', detail: '未发现押金、培训费、服装费等前置收费表述。' });
    }

    if (matched.gray) {
      checks.push({ status: 'fail', name: '工作内容', detail: '岗位疑似涉及刷单、返利等违规或灰产活动，建议立即停止沟通。' });
    } else if (hasContent) {
      checks.push({ status: 'pass', name: '工作内容', detail: '工作职责描述相对清晰，未发现明显灰产关键词。' });
    } else {
      checks.push({ status: 'warn', name: '工作内容', detail: '工作内容描述较少，建议要求对方补充具体职责与交付标准。' });
    }

    if (matched.contact) {
      checks.push({ status: 'warn', name: '联系规范', detail: '岗位方引导添加私人微信或站外私聊，脱离平台保障后维权难度较高。' });
    } else {
      checks.push({ status: 'pass', name: '联系规范', detail: '未发现明显的站外私下联系引导。' });
    }

    if (matched.noContract || (!hasContract && !matched.noContract)) {
      checks.push({
        status: matched.noContract ? 'fail' : 'warn',
        name: '合同用工',
        detail: matched.noContract ? '明确表示不签订合同，发生欠薪时举证困难。' : '未提及书面协议或合同，建议入职前确认工作约定。'
      });
    } else {
      checks.push({ status: 'pass', name: '合同用工', detail: '文本提及签订协议，建议确认协议中包含薪资与工作时间。' });
    }

    const failCount = checks.filter((check) => check.status === 'fail').length;
    const warnCount = checks.filter((check) => check.status === 'warn').length;
    const passCount = checks.filter((check) => check.status === 'pass').length;

    let level;
    if (score >= 85) {
      level = { label: '合规良好', badge: 'badge-green', color: '#3f7d57', verdict: '可优先考虑', copy: '未发现明显违规特征，仍建议核验商家资质并保留沟通记录。' };
    } else if (score >= 65) {
      level = { label: '基本合规', badge: 'badge-sand', color: '#b5842f', verdict: '谨慎核实后申请', copy: '发现少量不规范表述，建议进一步确认薪资、结算与用工细节。' };
    } else if (score >= 40) {
      level = { label: '中高风险', badge: 'badge-coral', color: '#d26a4c', verdict: '不建议直接申请', copy: '存在多项风险特征，请勿提前付款，并核实商家真实身份。' };
    } else {
      level = { label: '高风险', badge: 'badge-coral', color: '#c5533c', verdict: '强烈建议拒绝', copy: '检测到典型兼职诈骗特征，请立即停止沟通、保留证据并向平台举报。' };
    }

    const advice = [];
    if (matched.fee) advice.push('拒绝任何形式的入职前收费，正规岗位不会向求职者收取押金、服装费或培训费。');
    if (matched.gray) advice.push('刷单、返利、代注册等均可能涉及违法活动，请立即停止沟通并向平台举报。');
    if (matched.contact) advice.push('坚持在平台内沟通与交易，不要添加私人微信或向个人账户转账。');
    if (matched.noContract) advice.push('要求签订书面兼职协议，明确工作内容、薪资标准与结算时间。');
    if (!hasAmount) advice.push('主动询问并按「金额 + 计价单位 + 结算周期」确认薪资，截图留存。');
    if (!advice.length) advice.push('通过平台官方渠道沟通，入职前确认协议内容，并保存聊天、考勤与薪资记录。');
    advice.push('如已发生转账或纠纷，立即在平台发起快捷维权，并拨打 12333 咨询。');

    return {
      score,
      level,
      checks,
      riskWords: Array.from(riskWords),
      failCount,
      warnCount,
      passCount,
      advice: [...new Set(advice)]
    };
  }

  const contractSample = `兼职合作协议
甲方：星启文化传媒有限公司
乙方：马小满

一、乙方入职前需一次性缴纳服装费、培训费共 198 元，工作满 30 天后退还。
二、兼职工资统一于次月 30 日发放，若乙方中途离职，未结算工资不予支付。
三、甲方可根据经营需要随时调整乙方的工作内容和工作时长，乙方应无条件配合。
四、兼职期间如发生意外伤害，由乙方自行承担，甲方不承担任何责任。
五、本协议最终解释权归甲方所有，双方如有争议，以甲方认定为准。`;


  /* ------------------------- AI 合同风险检测 ------------------------- */

  const AI_SYSTEM_PROMPT = `你是「青薪盾」的兼职合同风险识别助手，服务对象是中国在校大学生。你的任务是逐条指出兼职协议、录用通知或兼职沟通记录中的风险条款，帮助同学保护自己。

规则：
1. 只做风险提示与沟通建议，不判定合同整体有效或无效，不给出“可以签 / 不能签”的结论，不冒充律师。
2. 法条只引用你确定存在的条文；不确定时写“暂无明确法条，建议参考《民法典》合同编相关规定”，禁止编造条号。
3. risks 至少 1 条、最多 8 条；即使文本没有明显风险，也要列出需要进一步确认的点。
4. 每条 risks 必须包含：level（high / medium / low）、clause（原文片段）、type（风险类型）、explanation（大白话解读）、law（法律依据）、advice（应对建议）、script（可直接发给对方的话术）。
5. score 为 0-100 的整数，表示安全程度，100 表示未发现风险。
6. 语言简洁、口语化、面向大学生。
7. 只输出合法 JSON，不要输出 Markdown 代码块、解释或多余文字。

JSON 结构：
{"score": 72, "level": "低风险|中风险|高风险", "overall": "一句话总体说明", "risks": [{"level": "high", "clause": "原文片段", "type": "收费风险", "explanation": "解读", "law": "法律依据", "advice": "建议", "script": "话术"}], "advice": ["整体建议1", "整体建议2"]}`;

  const AI_LEVEL_META = {
    high: { text: '高风险隐患', short: '高风险', badge: 'badge-coral', color: '#c5533c', verdict: '强烈建议先不要签署' },
    medium: { text: '中风险隐患', short: '中风险', badge: 'badge-coral', color: '#d26a4c', verdict: '建议逐条协商后再决定' },
    low: { text: '低风险提示', short: '低风险', badge: 'badge-green', color: '#3f7d57', verdict: '暂未发现明显高风险条款' }
  };

  function extractJson(raw) {
    let text = String(raw || '').trim();
    text = text.replace(/^```(?:json)?/i, '').replace(/```$/, '').trim();
    const start = text.indexOf('{');
    const end = text.lastIndexOf('}');
    if (start !== -1 && end > start) text = text.slice(start, end + 1);
    return JSON.parse(text);
  }

  function normalizeAiResult(data) {
    const risks = (Array.isArray(data.risks) ? data.risks : []).slice(0, 8).map((risk) => {
      const level = ['high', 'medium', 'low'].includes(risk.level) ? risk.level : 'medium';
      return {
        level,
        clause: String(risk.clause || '（未提供原文片段）').slice(0, 300),
        type: String(risk.type || '风险条款').slice(0, 30),
        explanation: String(risk.explanation || '该条款存在一定风险，建议与对方确认。'),
        law: String(risk.law || '暂无明确法条，建议参考《民法典》合同编相关规定。'),
        advice: String(risk.advice || '与对方书面确认后再决定是否签署。'),
        script: String(risk.script || '这条表述我还需要再确认一下，请改成更明确的书面约定。')
      };
    });

    if (!risks.length) {
      risks.push({
        level: 'low',
        clause: '（未识别到具体风险条款）',
        type: '信息完整性',
        explanation: '本次文本中未识别到明显的风险表述，但信息可能不完整。',
        law: '暂无明确法条，建议参考《民法典》合同编相关规定。',
        advice: '确认薪资标准、结算周期、工作内容与解除条件是否都已写入书面约定。',
        script: '请把薪资标准、结算时间和工作内容补充到书面协议里。'
      });
    }

    let score = Number(data.score);
    if (!Number.isFinite(score)) score = risks.some((risk) => risk.level === 'high') ? 45 : 70;
    score = Math.max(0, Math.min(100, Math.round(score)));

    const hasHigh = risks.some((risk) => risk.level === 'high');
    const hasMedium = risks.some((risk) => risk.level === 'medium');
    let level = 'low';
    if (hasHigh || score < 45) level = 'high';
    else if (hasMedium || score < 75) level = 'medium';

    return {
      score,
      level,
      overall: String(data.overall || '已完成条款风险识别，请逐条核对以下提示。').slice(0, 120),
      risks,
      advice: (Array.isArray(data.advice) ? data.advice : []).map(String).filter(Boolean).slice(0, 6)
    };
  }

  function updateAiUi() {
    const enabled = Boolean(state.aiApiKey);
    const pageStatus = $('#aiPageStatus');
    const keyState = $('#aiKeyState');
    const keyCurrent = $('#aiKeyCurrent');
    const runButton = $('#runComplianceScan');
    if (pageStatus) {
      pageStatus.innerHTML = `${icon(enabled ? 'sparkle' : 'info')}${enabled ? 'AI 检测已临时启用' : 'AI 检测暂停 · 本地规则可用'}`;
    }
    if (keyState) keyState.textContent = enabled ? 'AI 检测已临时启用' : 'AI 检测已暂停';
    if (keyCurrent) keyCurrent.textContent = enabled ? '已配置个人 Key（仅本次页面）' : '未配置个人 API Key';
    if (runButton) {
      runButton.innerHTML = `${icon(enabled ? 'sparkle' : 'shield')}${enabled ? '开始 AI 风险检测' : '使用本地规则自查'}`;
    }
  }

  async function requestAiScan(text) {
    if (!state.aiApiKey) throw new Error('未配置个人 API Key');
    const controller = new AbortController();
    const timer = window.setTimeout(() => controller.abort(), 45000);
    try {
      const response = await fetch(AI_CONFIG.endpoint, {
        method: 'POST',
        signal: controller.signal,
        headers: {
          'Content-Type': 'application/json',
          Authorization: `Bearer ${state.aiApiKey}`
        },
        body: JSON.stringify({
          model: AI_CONFIG.model,
          messages: [
            { role: 'system', content: AI_SYSTEM_PROMPT },
            { role: 'user', content: `请检测以下兼职文本中的风险条款，并按 JSON 结构输出结果：\n"""\n${text}\n"""` }
          ],
          temperature: 0.3,
          max_tokens: 1800,
          response_format: { type: 'json_object' },
          stream: false
        })
      });
      if (!response.ok) {
        const detail = await response.text().catch(() => '');
        throw new Error(`接口返回 ${response.status}${detail ? `：${detail.slice(0, 80)}` : ''}`);
      }
      const payload = await response.json();
      const content = payload?.choices?.[0]?.message?.content || '';
      if (!content) throw new Error('AI 未返回有效内容');
      return normalizeAiResult(extractJson(content));
    } catch (error) {
      if (error?.name === 'AbortError') throw new Error('请求超时，请稍后重试');
      throw error;
    } finally {
      window.clearTimeout(timer);
    }
  }

  function scoreGaugeHTML(score, color) {
    return `<div class="score-gauge" style="--score:${score};--gauge-color:${color}"><div><strong>${score}</strong><span>风险评分</span></div></div>`;
  }

  function reportActionsHTML() {
    return `
      <div class="report-actions">
        <button class="button button-light" data-rescan>重新检测</button>
        <button class="button button-dark" data-modal="safetyModal">查看安全规则</button>
      </div>
    `;
  }

  function reportDisclaimerHTML(kind = 'ai') {
    const text = kind === 'local'
      ? '本结果由本地规则引擎生成，仅基于关键词与信息完整度做初步筛查，可能存在遗漏或误判；不属于法律鉴定意见，不能替代执业律师法律服务；是否签约由学生本人自行判断。'
      : '本结果使用 AI 大模型（DeepSeek）辅助生成，仅识别展示合同风险隐患，AI 输出可能存在遗漏或误差；不属于法律鉴定意见，不能替代执业律师法律服务；是否签约由学生本人自行判断。';
    return `
      <div class="report-disclaimer">
        <strong>【免责提示】</strong>
        <p>${text}</p>
      </div>
    `;
  }

  function aiReportHTML(result) {
    const counts = { high: 0, medium: 0, low: 0 };
    result.risks.forEach((risk) => { counts[risk.level] += 1; });
    const level = AI_LEVEL_META[result.level] || AI_LEVEL_META.medium;
    return `
      <div class="contract-report-head">
        <div>
          <p class="eyebrow">AI CLAUSE RISK LIST</p>
          <h3>AI 合同风险逐条提示</h3>
          <p>由 DeepSeek 大模型识别，共 ${result.risks.length} 条风险；仅作参考，不构成法律意见。</p>
        </div>
        <span class="badge ${level.badge}">${level.short}</span>
      </div>
      <div class="report-top">
        ${scoreGaugeHTML(result.score, level.color)}
        <div class="report-verdict">
          <h3>${escapeHTML(result.overall)}</h3>
          <p>AI 综合评估：${level.verdict}。请逐条核对下列条款，并保留协商记录。</p>
        </div>
      </div>
      <div class="report-stats">
        <div class="report-stat"><span>高风险条款</span><strong>${counts.high} 条</strong></div>
        <div class="report-stat"><span>中风险条款</span><strong>${counts.medium} 条</strong></div>
        <div class="report-stat"><span>低风险提示</span><strong>${counts.low} 条</strong></div>
      </div>
      <div class="contract-risk-list">
        ${result.risks.map((risk, index) => `
          <article class="contract-risk-item ${risk.level}">
            <div class="contract-risk-head">
              <span class="risk-level-pill ${risk.level}"><i></i>${AI_LEVEL_META[risk.level].text}</span>
              <span class="risk-index">${escapeHTML(risk.type)} · 风险 ${String(index + 1).padStart(2, '0')}</span>
            </div>
            <div class="risk-clause-label">原文片段</div>
            <blockquote class="risk-clause">${escapeHTML(risk.clause)}</blockquote>
            <div class="risk-field-grid">
              <div class="risk-field"><span>大白话解读</span><p>${escapeHTML(risk.explanation)}</p></div>
              <div class="risk-field"><span>法条提示</span><p>${escapeHTML(risk.law)}</p></div>
              <div class="risk-field"><span>应对建议</span><p>${escapeHTML(risk.advice)}</p></div>
              <div class="risk-field script"><span>沟通话术</span><p>${escapeHTML(risk.script)}</p></div>
            </div>
          </article>
        `).join('')}
      </div>
      ${result.advice.length ? `<div class="report-advice"><strong>整体建议</strong><ul>${result.advice.map((item) => `<li>${escapeHTML(item)}</li>`).join('')}</ul></div>` : ''}
      ${reportActionsHTML()}
      ${reportDisclaimerHTML()}
    `;
  }

  function localReportHTML(result, notice) {
    const statusMeta = {
      pass: { text: '通过', icon: 'check' },
      warn: { text: '提醒', icon: 'info' },
      fail: { text: '风险', icon: 'alert' }
    };
    return `
      <div class="contract-report-head">
        <div>
          <p class="eyebrow">RULE BASED CHECK</p>
          <h3>本地规则检测结果</h3>
          <p>基于关键词与信息完整度的初步筛查，仅作参考。</p>
        </div>
        <span class="badge badge-sand">本地规则</span>
      </div>
      ${notice ? `<div class="ai-summary">${icon('info')}<p>${escapeHTML(notice)}</p></div>` : ''}
      <div class="report-top">
        ${scoreGaugeHTML(result.score, result.level.color)}
        <div class="report-verdict">
          <h3>${escapeHTML(result.level.verdict)}</h3>
          <p>${escapeHTML(result.level.copy)}</p>
        </div>
      </div>
      <div class="report-stats">
        <div class="report-stat"><span>通过项</span><strong>${result.passCount} 项</strong></div>
        <div class="report-stat"><span>提醒项</span><strong>${result.warnCount} 项</strong></div>
        <div class="report-stat"><span>风险项</span><strong>${result.failCount} 项</strong></div>
      </div>
      <div class="report-checks">
        ${result.checks.map((check) => `
          <div class="report-check ${check.status}">
            <span class="report-check-icon">${icon(statusMeta[check.status].icon)}</span>
            <div><strong>${escapeHTML(check.name)}<em>${statusMeta[check.status].text}</em></strong><p>${escapeHTML(check.detail)}</p></div>
          </div>
        `).join('')}
      </div>
      ${result.riskWords.length ? `<div class="report-keywords">${result.riskWords.map((word) => `<span>${escapeHTML(word)}</span>`).join('')}</div>` : ''}
      <div class="report-advice"><strong>处理建议</strong><ul>${result.advice.map((item) => `<li>${escapeHTML(item)}</li>`).join('')}</ul></div>
      ${reportActionsHTML()}
      ${reportDisclaimerHTML('local')}
    `;
  }

  const wait = (ms) => new Promise((resolve) => window.setTimeout(resolve, ms));

  async function runComplianceScan() {
    if (state.scanning) return;
    const input = $('#complianceInput');
    const placeholder = $('#scanPlaceholder');
    const loading = $('#scanLoading');
    const report = $('#scanReport');
    const button = $('#runComplianceScan');
    const text = input?.value.trim() || '';
    const aiEnabled = Boolean(state.aiApiKey);

    if (text.length < 10) {
      showToast('请先粘贴至少 10 个字的合同内容', 'error');
      input?.focus();
      return;
    }

    state.scanning = true;
    state.scanTimers.forEach((timer) => clearTimeout(timer));
    state.scanTimers = [];
    placeholder?.classList.add('hidden');
    report?.classList.remove('visible');
    if (report) report.innerHTML = '';
    loading?.classList.add('visible');
    if (button) {
      button.disabled = true;
      button.style.opacity = '0.7';
      button.innerHTML = `${icon(aiEnabled ? 'sparkle' : 'shield')}${aiEnabled ? 'AI 正在检测...' : '正在执行本地规则...'}`;
    }

    const phases = aiEnabled ? [
      '正在将文本发送至 AI 检测服务...',
      'AI 正在逐条比对收费、结算与免责条款...',
      '正在整理风险等级与沟通建议...'
    ] : [
      '正在读取合同条款...',
      '正在匹配本地风险规则...',
      '正在整理风险提示与沟通建议...'
    ];
    let phaseIndex = 0;
    const setPhase = () => {
      const loadingText = $('#scanLoadingText');
      if (loadingText) loadingText.textContent = phases[phaseIndex % phases.length];
      phaseIndex += 1;
    };
    setPhase();
    const phaseTimer = window.setInterval(setPhase, 2200);
    const startedAt = Date.now();

    let html;
    try {
      if (aiEnabled) {
        try {
          const result = await requestAiScan(text);
          html = aiReportHTML(result);
        } catch (error) {
          console.error('[青薪盾] AI 检测失败：', error);
          html = localReportHTML(scanText(text), `AI 检测调用失败（${error?.message || '网络异常'}）。已切换为本地规则结果，请核对后再作判断。`);
          showToast('AI 服务暂不可用，已切换为本地规则检测', 'error');
        }
      } else {
        html = localReportHTML(scanText(text), 'AI 检测当前默认关闭，本次结果由本地规则引擎生成，仅作初步筛查。');
      }

      await wait(Math.max(0, 900 - (Date.now() - startedAt)));
      window.clearInterval(phaseTimer);
      loading?.classList.remove('visible');
      if (report) {
        report.innerHTML = html;
        report.classList.add('visible');
      }
    } finally {
      window.clearInterval(phaseTimer);
      loading?.classList.remove('visible');
      if (button) {
        button.disabled = false;
        button.style.opacity = '';
        updateAiUi();
      }
      state.scanning = false;
      if (window.innerWidth < 700) {
        $('#scanResultCard')?.scrollIntoView({ behavior: 'smooth', block: 'start' });
      }
    }
  }

  function validateReliefStep(step) {
    const panel = $(`[data-relief-panel="${step}"]`);
    if (!panel) return true;
    let firstInvalid = null;
    $$('[required]', panel).forEach((field) => {
      field.classList.remove('invalid');
      const empty = field.type === 'checkbox' ? !field.checked : !String(field.value || '').trim();
      if (empty) {
        field.classList.add('invalid');
        if (!firstInvalid) firstInvalid = field;
      }
    });
    if (step === 1) {
      const phone = $('[name="phone"]', panel);
      if (phone && phone.value.replace(/\D/g, '').length < 7) {
        phone.classList.add('invalid');
        if (!firstInvalid) firstInvalid = phone;
      }
    }
    if (step === 2) {
      const amount = $('[name="amount"]', panel);
      if (amount && Number(amount.value) <= 0) {
        amount.classList.add('invalid');
        if (!firstInvalid) firstInvalid = amount;
      }
    }
    if (firstInvalid) {
      showToast('请完善标记为必填的信息', 'error');
      firstInvalid.focus();
      return false;
    }
    return true;
  }

  function setReliefStep(step, scroll = true) {
    state.reliefStep = Math.min(4, Math.max(1, step));
    $$('.relief-step-panel').forEach((panel) => panel.classList.toggle('active', Number(panel.dataset.reliefPanel) === state.reliefStep));
    $$('#reliefStepper .step').forEach((item) => {
      const itemStep = Number(item.dataset.step);
      item.classList.toggle('active', itemStep === state.reliefStep);
      item.classList.toggle('completed', itemStep < state.reliefStep);
    });
    const prev = $('#reliefPrevButton');
    const next = $('#reliefNextButton');
    const submit = $('#reliefSubmitButton');
    if (prev) prev.hidden = state.reliefStep === 1;
    if (next) next.hidden = state.reliefStep === 4;
    if (submit) submit.hidden = state.reliefStep !== 4;
    if (state.reliefStep === 4) fillReliefReview();
    if (scroll) $('#reliefFormCard')?.scrollIntoView({ behavior: 'smooth', block: 'start' });
  }

  function fillReliefReview() {
    const form = $('#reliefForm');
    if (!form) return;
    const data = new FormData(form);
    const review = $('#reliefReview');
    if (!review) return;
    const value = (key, fallback = '未填写') => escapeHTML(data.get(key) || fallback);
    review.innerHTML = `
      <div class="review-item"><span>申请人</span><strong>${value('name')}</strong></div>
      <div class="review-item"><span>就读院校</span><strong>${value('school')}</strong></div>
      <div class="review-item"><span>联系电话</span><strong>${value('phone')}</strong></div>
      <div class="review-item"><span>被骗类型</span><strong>${value('fraudType')}</strong></div>
      <div class="review-item"><span>涉事商家</span><strong>${value('merchant')}</strong></div>
      <div class="review-item"><span>被骗金额</span><strong>¥${formatMoney(data.get('amount'))}</strong></div>
      <div class="review-item"><span>被骗日期</span><strong>${value('date')}</strong></div>
      <div class="review-item"><span>支付方式</span><strong>${value('payment')}</strong></div>
      <div class="review-item"><span>报警情况</span><strong>${value('police')}</strong></div>
      <div class="review-item"><span>学生身份</span><strong>${value('identity')}</strong></div>
      <div class="review-item full"><span>事件经过</span><strong>${value('detail')}</strong></div>
    `;
  }

  function attachUploadPreview(input, list) {
    if (!input || !list) return;
    input.addEventListener('change', () => {
      const files = Array.from(input.files || []);
      list.innerHTML = files.map((file) => `<span class="file-chip">${icon('file')}${escapeHTML(file.name)}</span>`).join('');
    });
    const zone = input.closest('.upload-zone');
    if (zone) {
      ['dragenter', 'dragover'].forEach((eventName) => zone.addEventListener(eventName, (event) => {
        event.preventDefault();
        zone.classList.add('dragover');
      }));
      ['dragleave', 'drop'].forEach((eventName) => zone.addEventListener(eventName, (event) => {
        event.preventDefault();
        zone.classList.remove('dragover');
      }));
      zone.addEventListener('drop', (event) => {
        const files = event.dataTransfer?.files;
        if (!files || !files.length) return;
        try {
          const transfer = new DataTransfer();
          Array.from(files).forEach((file) => transfer.items.add(file));
          input.files = transfer.files;
          input.dispatchEvent(new Event('change'));
        } catch (error) {
          list.innerHTML = Array.from(files).map((file) => `<span class="file-chip">${icon('file')}${escapeHTML(file.name)}</span>`).join('');
        }
      });
    }
  }

  function collectFiles(inputId) {
    const input = $(`#${inputId}`);
    return Array.from(input?.files || []).map((file) => file.name);
  }

  function nowStamp() {
    const now = new Date();
    return `${now.getFullYear()}-${String(now.getMonth() + 1).padStart(2, '0')}-${String(now.getDate()).padStart(2, '0')} ${String(now.getHours()).padStart(2, '0')}:${String(now.getMinutes()).padStart(2, '0')}`;
  }

  function makeCaseId(prefix) {
    const now = new Date();
    const date = `${now.getFullYear()}${String(now.getMonth() + 1).padStart(2, '0')}${String(now.getDate()).padStart(2, '0')}`;
    return `${prefix}${date}${String(Math.floor(Math.random() * 900) + 100)}`;
  }

  function markInvalid(fields) {
    let firstInvalid = null;
    fields.forEach((field) => {
      if (!field) return;
      field.classList.remove('invalid');
      const empty = field.type === 'checkbox' ? !field.checked : !String(field.value || '').trim();
      if (empty) {
        field.classList.add('invalid');
        if (!firstInvalid) firstInvalid = field;
      }
    });
    if (firstInvalid) {
      showToast('请完善标记为必填的信息', 'error');
      firstInvalid.focus();
      return false;
    }
    return true;
  }

  function handleRightsSubmit(form) {
    const fields = ['merchant', 'type', 'detail', 'phone'].map((name) => form.elements[name]);
    fields.push(form.elements.truth);
    if (!markInvalid(fields)) return;

    const data = new FormData(form);
    const amount = Number(data.get('amount') || 0);
    const files = collectFiles('rightsFiles');
    const record = {
      id: makeCaseId('WQ'),
      type: String(data.get('type') || '其他权益受损'),
      amount: amount > 0 ? `¥${formatMoney(amount)}` : '不涉及金额',
      date: String(data.get('date') || nowStamp().slice(0, 10)),
      submittedAt: nowStamp(),
      status: '演示已记录',
      merchant: String(data.get('merchant') || ''),
      phone: String(data.get('phone') || ''),
      detail: String(data.get('detail') || ''),
      files: files.length ? files : ['聊天记录截图 · 待补充', '转账凭证 · 待补充'],
      timeline: [
        { state: 'done', title: '演示工单已生成', note: '刚刚 · 仅保存在当前页面' },
        { state: 'active', title: '公共维权指引', note: '请联系 12315 / 12333 或报警 110' },
        { state: '', title: '调解资源对接', note: '规划中，当前不提供实时调解' },
        { state: '', title: '处理完成', note: '以真实渠道处理结果为准' }
      ],
      handler: { name: '平台规则小组', meta: '展示样例 · 非真实调解人员', avatar: '盾' },
      messages: [
        { who: '展示提示', text: '当前展示版仅在本地生成工单记录，不会发送至真实调解机构。紧急情况请拨打 110、12315 或 12333。', time: '刚刚' }
      ]
    };
    state.rightsCase = record;

    const summaryId = $('#caseSummaryId');
    const summaryMeta = $('#caseSummaryMeta');
    const statusBadge = $('#caseStatusBadge');
    const timeline = $('#caseTimeline');
    const progress = $('#caseProgressBar span');
    const latest = $('#latestCaseNumber');
    if (latest) latest.textContent = record.id;
    if (summaryId) summaryId.textContent = record.id;
    if (summaryMeta) summaryMeta.textContent = `${record.type} · ${record.amount}`;
    if (statusBadge) {
      statusBadge.textContent = '演示已记录';
      statusBadge.className = 'badge badge-green';
    }
    if (timeline) timeline.innerHTML = timelineItemsHTML(record.timeline);
    if (progress) progress.style.width = '20%';

    form.reset();
    const fileList = $('#rightsFileList');
    if (fileList) fileList.innerHTML = '';
    showToast(`演示工单 ${record.id} 已生成，未发送至外部机构`, 'info');
    $('.progress-card')?.scrollIntoView({ behavior: 'smooth', block: 'center' });
  }

  function handlePublishSubmit(form) {
    const fields = ['title', 'category', 'pay', 'settlement', 'location', 'schedule', 'description'].map((name) => form.elements[name]);
    fields.push(form.elements.agreement);
    if (!markInvalid(fields)) return;

    const data = new FormData(form);
    const tags = String(data.get('tags') || '')
      .split(/[,，]/)
      .map((tag) => tag.trim())
      .filter(Boolean);
    state.merchantJobs.unshift({
      id: `pos-${Date.now()}`,
      title: String(data.get('title') || '新岗位'),
      meta: `${String(data.get('location') || '')} · ${String(data.get('schedule') || '')}`,
      pay: String(data.get('pay') || ''),
      settlement: String(data.get('settlement') || ''),
      riskCount: 0,
      status: 'pending',
      tags,
      logo: 'M',
      logoClass: 'logo-mstand'
    });
    renderMerchantJobs();
    switchMerchantTab('manage');
    form.reset();
    showToast('提交成功，岗位已进入检测队列');
  }

  function handleReliefSubmit(form) {
    for (let step = 1; step <= 3; step += 1) {
      if (!validateReliefStep(step)) {
        setReliefStep(step, false);
        return;
      }
    }
    const agreement = form.elements.reliefAgreement;
    if (agreement) {
      agreement.classList.remove('invalid');
      if (!agreement.checked) {
        agreement.classList.add('invalid');
        showToast('请先勾选同意服务说明', 'error');
        agreement.focus();
        return;
      }
    }

    const data = new FormData(form);
    const amount = Number(data.get('amount') || 0);
    const files = collectFiles('reliefFiles');
    const record = {
      id: makeCaseId('AJ'),
      type: String(data.get('fraudType') || '其他类型'),
      amount: amount > 0 ? `¥${formatMoney(amount)}` : '未填写',
      status: '演示记录',
      date: String(data.get('date') || nowStamp().slice(0, 10)),
      name: String(data.get('name') || ''),
      school: String(data.get('school') || ''),
      phone: String(data.get('phone') || ''),
      merchant: String(data.get('merchant') || ''),
      payment: String(data.get('payment') || ''),
      police: String(data.get('police') || '未报警'),
      detail: String(data.get('detail') || ''),
      files: files.length ? files : ['聊天记录截图 · 待补充', '转账凭证 · 待补充'],
      timeline: [
        { state: 'done', title: '展示记录已生成', note: '刚刚 · 仅保存在当前页面' },
        { state: 'active', title: '公共维权指引', note: '请联系 110 / 12315 / 12333' },
        { state: '', title: '公益资源对接', note: '规划中，当前不提供真实援助' },
        { state: '', title: '处理完成', note: '以真实渠道处理结果为准' }
      ],
      messages: [
        { who: '展示提示', text: '展示版仅在当前页面生成记录，不会触发真实外部受理。紧急情况请拨打 110、12315 或 12333。', time: '刚刚' }
      ]
    };
    state.reliefHistory.unshift(record);
    renderReliefHistory();

    const numberEl = $('#reliefCaseNumber');
    if (numberEl) numberEl.textContent = record.id;
    const viewBtn = $('#viewReliefRecord');
    if (viewBtn) viewBtn.dataset.reliefId = record.id;

    const formEl = $('#reliefForm');
    const stepper = $('#reliefStepper');
    if (formEl) formEl.style.display = 'none';
    if (stepper) stepper.style.display = 'none';
    $('#reliefSuccess')?.classList.add('visible');
    showToast('展示版记录已生成，不会触发真实外部受理', 'info');
    $('#reliefFormCard')?.scrollIntoView({ behavior: 'smooth', block: 'start' });
  }

  function resetReliefView() {
    const success = $('#reliefSuccess');
    if (!success?.classList.contains('visible')) return;
    const form = $('#reliefForm');
    const stepper = $('#reliefStepper');
    success.classList.remove('visible');
    if (form) {
      form.style.display = '';
      form.reset();
    }
    if (stepper) stepper.style.display = '';
    const fileList = $('#reliefFileList');
    if (fileList) fileList.innerHTML = '';
    state.reliefStep = 1;
    setReliefStep(1, false);
  }

  function wireEvents() {
    document.addEventListener('submit', (event) => {
      const form = event.target;
      if (!form || form.id === 'heroSearchForm') return;
      event.preventDefault();
      if (form.id === 'rightsForm') handleRightsSubmit(form);
      else if (form.id === 'publishJobForm') handlePublishSubmit(form);
      else if (form.id === 'reliefForm') handleReliefSubmit(form);
      else returnHome();
    });

    document.addEventListener('click', (event) => {
      const jobCard = event.target.closest('.job-card');
      if (jobCard) {
        openJobModal(jobCard.dataset.jobId);
        return;
      }

      const recordTrigger = event.target.closest('[data-open-record]');
      if (recordTrigger) {
        openRecord(recordTrigger.dataset.openRecord, recordTrigger.dataset.reliefId);
        return;
      }

      const modalTrigger = event.target.closest('[data-modal]');
      if (modalTrigger) {
        event.preventDefault();
        openModal(modalTrigger.dataset.modal);
        return;
      }

      const pageTrigger = event.target.closest('[data-page]');
      if (pageTrigger) {
        event.preventDefault();
        $$('.modal-backdrop.open').forEach((modal) => {
          if (modal.id !== 'complianceGate') closeModal(modal.id);
        });
        navigate(pageTrigger.dataset.page);
        if (pageTrigger.dataset.toast) showToast(pageTrigger.dataset.toast, 'info');
        return;
      }

      const closeTrigger = event.target.closest('[data-close-modal]');
      if (closeTrigger) {
        closeModal(closeTrigger.dataset.closeModal);
        return;
      }

      if (event.target.classList.contains('modal-backdrop')) {
        if (event.target.dataset.locked === 'true') return;
        closeModal(event.target.id);
        return;
      }

      const merchantTab = event.target.closest('[data-merchant-tab]');
      if (merchantTab) {
        switchMerchantTab(merchantTab.dataset.merchantTab);
        return;
      }

      const accordion = event.target.closest('.accordion-trigger');
      if (accordion) {
        const expanded = accordion.getAttribute('aria-expanded') === 'true';
        const content = accordion.nextElementSibling;
        $$('.accordion-trigger').forEach((trigger) => {
          if (trigger !== accordion) {
            trigger.setAttribute('aria-expanded', 'false');
            trigger.nextElementSibling?.classList.remove('open');
          }
        });
        accordion.setAttribute('aria-expanded', String(!expanded));
        content?.classList.toggle('open', !expanded);
        return;
      }

      const sample = event.target.closest('[data-sample]');
      if (sample) {
        const input = $('#complianceInput');
        if (input) {
          input.value = contractSample;
          input.dispatchEvent(new Event('input'));
          input.focus();
        }
        return;
      }

      if (event.target.closest('[data-rescan]')) {
        runComplianceScan();
        return;
      }

      if (event.target.closest('[data-export-records]')) {
        exportRecords();
        return;
      }

      if (event.target.closest('[data-scan-rights]')) {
        navigate('rights');
        window.setTimeout(() => {
          const detail = $('#rightsForm [name="detail"]');
          const input = $('#complianceInput');
          if (detail && input?.value) detail.value = `我看到一条疑似违规的岗位信息，希望平台核实：\n${input.value.slice(0, 500)}`;
        }, 120);
        showToast('已带你进入维权申请，请补充联系方式', 'info');
        return;
      }

      const toastTrigger = event.target.closest('[data-toast]');
      if (toastTrigger) {
        showToast(toastTrigger.dataset.toast, 'info');
        return;
      }

      const channel = event.target.closest('.channel-card');
      if (channel) {
        showToast('服务入口已接入，演示版本可继续使用下方表单', 'info');
        return;
      }

      if (!event.target.closest('.notification-wrap')) {
        $('#notificationPopover')?.classList.remove('open');
      }
    });

    document.addEventListener('keydown', (event) => {
      if (event.key === 'Escape') {
        $$('.modal-backdrop.open').forEach((modal) => {
          if (modal.dataset.locked !== 'true') closeModal(modal.id);
        });
        closeSidebar();
        $('#notificationPopover')?.classList.remove('open');
      }
      if ((event.key === 'Enter' || event.key === ' ') && event.target.classList.contains('job-card')) {
        event.preventDefault();
        openJobModal(event.target.dataset.jobId);
      }
    });

    document.addEventListener('input', (event) => {
      if (event.target.matches('input, select, textarea')) {
        event.target.classList.remove('invalid');
      }
    });

    $('#sidebarScrim')?.addEventListener('click', closeSidebar);
    $('#menuButton')?.addEventListener('click', openSidebar);

    window.addEventListener('hashchange', () => {
      activatePage(location.hash.replace('#', '') || 'dashboard');
    });

    $('#notificationButton')?.addEventListener('click', (event) => {
      event.stopPropagation();
      $('#notificationPopover')?.classList.toggle('open');
    });

    $('#markRead')?.addEventListener('click', () => {
      $('.notification-dot')?.remove();
      $('#notificationPopover')?.classList.remove('open');
      showToast('所有消息已标记为已读');
    });

    $('#acceptComplianceGate')?.addEventListener('click', () => {
      closeModal('complianceGate');
      window.setTimeout(() => $('#complianceInput')?.focus(), 120);
    });

    $('#saveAiKey')?.addEventListener('click', () => {
      const input = $('#deepseekApiKey');
      const key = String(input?.value || '').trim();
      if (key.length < 10) {
        showToast('请填写有效的 DeepSeek API Key', 'error');
        input?.focus();
        return;
      }
      state.aiApiKey = key;
      if (input) input.value = '';
      updateAiUi();
      showToast('AI 检测已在当前页面临时启用');
    });

    $('#toggleAiKey')?.addEventListener('click', (event) => {
      const input = $('#deepseekApiKey');
      if (!input) return;
      const showing = input.type === 'text';
      input.type = showing ? 'password' : 'text';
      event.currentTarget.textContent = showing ? '显示' : '隐藏';
    });

    $('#clearAiKey')?.addEventListener('click', () => {
      state.aiApiKey = '';
      const input = $('#deepseekApiKey');
      if (input) {
        input.value = '';
        input.type = 'password';
      }
      const toggle = $('#toggleAiKey');
      if (toggle) toggle.textContent = '显示';
      updateAiUi();
      showToast('已清除当前页面的 API Key', 'info');
    });

    $('#heroSearchForm')?.addEventListener('submit', (event) => {
      event.preventDefault();
      setJobSearch($('#heroSearchInput')?.value || '');
    });

    $$('[data-search-keyword]').forEach((button) => {
      button.addEventListener('click', () => setJobSearch(button.dataset.searchKeyword));
    });

    $('#jobSearchInput')?.addEventListener('input', (event) => {
      state.search = event.target.value;
      renderJobGrids();
    });

    $('#jobLocationFilter')?.addEventListener('change', (event) => {
      state.location = event.target.value;
      renderJobGrids();
    });

    $('#jobSortFilter')?.addEventListener('change', (event) => {
      state.sort = event.target.value;
      renderJobGrids();
    });

    $('#jobCategoryFilters')?.addEventListener('click', (event) => {
      const chip = event.target.closest('[data-category]');
      if (!chip) return;
      state.category = chip.dataset.category;
      $$('#jobCategoryFilters .chip').forEach((item) => item.classList.toggle('active', item === chip));
      renderJobGrids();
    });

    $('#resetJobFilters')?.addEventListener('click', () => {
      state.category = '全部';
      state.search = '';
      state.location = 'all';
      state.sort = 'recommend';
      if ($('#jobSearchInput')) $('#jobSearchInput').value = '';
      if ($('#jobLocationFilter')) $('#jobLocationFilter').value = 'all';
      if ($('#jobSortFilter')) $('#jobSortFilter').value = 'recommend';
      $$('#jobCategoryFilters .chip').forEach((item) => item.classList.toggle('active', item.dataset.category === '全部'));
      renderJobGrids();
    });

    $('#complianceInput')?.addEventListener('input', (event) => {
      const count = $('#scanCharCount');
      if (count) count.textContent = String(event.target.value.length);
    });
    $('#runComplianceScan')?.addEventListener('click', () => runComplianceScan());
    $('#clearCompliance')?.addEventListener('click', () => {
      const input = $('#complianceInput');
      if (input) {
        input.value = '';
        input.dispatchEvent(new Event('input'));
        input.focus();
      }
      $('#scanPlaceholder')?.classList.remove('hidden');
      $('#scanLoading')?.classList.remove('visible');
      $('#scanReport')?.classList.remove('visible');
    });

    attachUploadPreview($('#rightsFiles'), $('#rightsFileList'));
    attachUploadPreview($('#reliefFiles'), $('#reliefFileList'));

    $('#clockButton')?.addEventListener('click', () => {
      if (clock.running) stopClock();
      else startClock();
    });
    $('#resetClockButton')?.addEventListener('click', resetClock);

    $('#reliefNextButton')?.addEventListener('click', () => {
      if (!validateReliefStep(state.reliefStep)) return;
      setReliefStep(state.reliefStep + 1);
    });
    $('#reliefPrevButton')?.addEventListener('click', () => setReliefStep(state.reliefStep - 1));

    $('#copyReliefCase')?.addEventListener('click', async () => {
      const caseNumber = $('#reliefCaseNumber')?.textContent || '';
      try {
        await navigator.clipboard.writeText(caseNumber);
        showToast('申请编号已复制');
      } catch (error) {
        showToast(`申请编号：${caseNumber}`, 'info');
      }
    });

    $('#newReliefButton')?.addEventListener('click', () => navigate('dashboard'));

    $('#recordBackButton')?.addEventListener('click', () => {
      navigate(state.recordReturn || state.recordNav || 'rights');
    });

    $('#viewReliefRecord')?.addEventListener('click', (event) => {
      const id = event.currentTarget.dataset.reliefId || state.reliefHistory[0]?.id;
      if (id) openRecord('relief', id);
    });

    $('#syncReliefToRights')?.addEventListener('click', () => {
      const record = state.reliefHistory[0];
      if (!record) return;
      window.setTimeout(() => {
        const form = $('#rightsForm');
        if (!form) return;
        form.elements.merchant.value = record.merchant || '';
        form.elements.amount.value = String(record.amount || '').replace(/[^\d.]/g, '');
        form.elements.type.value = '收取押金或培训费';
        form.elements.detail.value = `【由救济申请 ${record.id} 同步】\n${record.detail || ''}`;
        showToast('已带入救济申请信息，请补充后提交', 'info');
      }, 180);
    });
  }

  function setJobSearch(keyword) {
    state.search = keyword;
    state.category = '全部';
    const search = $('#jobSearchInput');
    if (search) search.value = keyword;
    $$('#jobCategoryFilters .chip').forEach((item) => item.classList.toggle('active', item.dataset.category === '全部'));
    renderJobGrids();
    navigate('jobs');
  }

  function init() {
    wireEvents();
    renderJobGrids();
    const navBadge = $('#jobsNavBadge');
    if (navBadge) navBadge.textContent = String(jobs.length);
    renderMerchantJobs();
    restoreWallet();
    restoreClock();
    renderReliefHistory();
    updateAiUi();

    const initialPage = location.hash.replace('#', '') || 'dashboard';
    if (!location.hash) {
      history.replaceState(null, '', '#dashboard');
    }
    activatePage(initialPage);
    setReliefStep(1, false);
    if ($('#complianceInput')) $('#scanCharCount').textContent = String($('#complianceInput').value.length);
  }

  init();
})();
