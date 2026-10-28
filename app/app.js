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
    jobs: '招聘大厅',
    merchant: '商家中心',
    profile: '个人画像',
    wallet: '薪资结算',
    compliance: '合规检测',
    rights: '快捷维权',
    relief: '被骗救济'
  };

  const jobs = [
    {
      id: 'job-1',
      title: '周末咖啡店店员',
      merchant: 'M Stand 咖啡',
      category: '门店服务',
      pay: '200',
      unit: '元/天',
      paySort: 200,
      settlement: '日结',
      location: '徐汇 · 漕河泾',
      area: '徐汇',
      distance: '距你 2.4km',
      schedule: '周六日 10:00-18:00',
      tags: ['包午餐', '地铁周边', '可连做'],
      safety: 96,
      urgent: true,
      logo: 'M',
      logoClass: 'logo-mstand',
      rating: '4.9',
      applicants: 28,
      description: '负责门店点单、饮品制作辅助、取餐区整理与顾客接待。门店氛围轻松，提供完整岗前培训，无需咖啡经验。',
      requirements: ['有服务意识，沟通自然', '可连续工作 4 个周末', '持健康证或可在入职前办理'],
      highlight: '商家已实名认证 · 薪资已进入平台担保'
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
      safety: 92,
      urgent: false,
      logo: '知',
      logoClass: 'logo-blue',
      rating: '4.8',
      applicants: 41,
      description: '运营校园新媒体账号，完成选题策划、图文编辑与社群互动。每周提交内容排期，数据表现优秀另有奖励。',
      requirements: ['熟悉小红书 / 公众号内容生态', '具备基础图片编辑能力', '每周可投入 12 小时以上'],
      highlight: '线上签约 · 周结薪资已托管'
    },
    {
      id: 'job-3',
      title: '展会双语引导',
      merchant: '上海澜图会展',
      category: '活动执行',
      pay: '260',
      unit: '元/天',
      paySort: 260,
      settlement: '日结',
      location: '青浦 · 国家会展中心',
      area: '青浦',
      distance: '地铁 2 号线直达',
      schedule: '11 月 12 日-14 日 08:30-17:30',
      tags: ['英语口语', '提供工作餐', '三天连做'],
      safety: 94,
      urgent: true,
      logo: '澜',
      logoClass: 'logo-coral',
      rating: '4.9',
      applicants: 17,
      description: '负责展会入口引导、嘉宾接待与双语咨询，协助现场秩序维护。活动前提供统一培训与工作证件。',
      requirements: ['英语口语流利，CET-6 优先', '形象大方，有展会经验优先', '可完成三天连续工作'],
      highlight: '大型活动备案 · 每日完工即结'
    },
    {
      id: 'job-4',
      title: '数据标注实习生',
      merchant: '云粒科技',
      category: '线上兼职',
      pay: '25',
      unit: '元/小时',
      paySort: 25,
      settlement: '月结',
      location: '线上 · 远程',
      area: '线上',
      distance: '远程办公',
      schedule: '每周 10-15 小时 · 自由排班',
      tags: ['远程', '技能培训', '实习证明'],
      safety: 88,
      urgent: false,
      logo: '云',
      logoClass: 'logo-purple',
      rating: '4.7',
      applicants: 63,
      description: '根据标注规范完成图像与文本数据整理，协助质检样本。任务按批次发放，提供线上培训与答疑支持。',
      requirements: ['耐心细致，能长期参与', '自备电脑与稳定网络', '每周至少完成 10 小时'],
      highlight: '企业实名认证 · 平台月度结算'
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
      location: '浦东 · 金桥',
      area: '浦东',
      distance: '距你 5.1km',
      schedule: '工作日 16:30-19:30',
      tags: ['师范优先', '周结', '提供晚餐'],
      safety: 90,
      urgent: false,
      logo: '树',
      logoClass: 'logo-sand',
      rating: '4.8',
      applicants: 23,
      description: '辅导小学阶段学生完成课后作业，维持课堂秩序，并与家长进行简单反馈。每班不超过 8 名学生。',
      requirements: ['本科在读，师范专业优先', '有耐心，善于与孩子沟通', '每周至少到岗 3 天'],
      highlight: '办学资质已核验 · 一对一岗前带教'
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
      location: '静安 · 大宁',
      area: '静安',
      distance: '距你 4.8km',
      schedule: '周六日 11:00-19:00',
      tags: ['宠物友好', '日结', '可撸猫'],
      safety: 85,
      urgent: false,
      logo: '毛',
      logoClass: 'logo-coral',
      rating: '4.7',
      applicants: 32,
      description: '协助完成宠物洗护区清理、用品整理与顾客接待，不涉及专业洗护操作。店内有猫，需对宠物毛发不过敏。',
      requirements: ['喜欢小动物，不怕猫狗', '可接受站立工作', '周末可稳定到岗'],
      highlight: '到店打卡 · 完工当日结算'
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
      safety: 91,
      urgent: false,
      logo: '野',
      logoClass: 'logo-purple',
      rating: '4.9',
      applicants: 38,
      description: '根据脚本完成 60 秒以内短视频剪辑，包含基础字幕、节奏卡点与封面制作。试稿通过后进入长期合作池。',
      requirements: ['熟练使用剪映 / PR', '有短视频作品可展示', '能在约定时间内交付'],
      highlight: '项目合同 · 验收后平台放款'
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
      location: '杨浦 · 五角场',
      area: '杨浦',
      distance: '距你 3.2km',
      schedule: '可排班 · 每次 4 小时起',
      tags: ['排班灵活', '就近安排', '日结'],
      safety: 89,
      urgent: false,
      logo: '邻',
      logoClass: 'logo-blue',
      rating: '4.6',
      applicants: 46,
      description: '负责货架商品整理、价签核对与简单库存盘点，协助高峰时段的顾客引导。工作强度适中。',
      requirements: ['认真负责，能接受站立工作', '每周可排班 2 次以上', '可长期兼职优先'],
      highlight: '门店直招 · 工时打卡自动结算'
    }
  ];

  const initialTransactions = [
    { type: 'in', title: '校园新媒体运营 · 周结', meta: '10 月 18 日 14:32 · 支付宝到账', amount: 450 },
    { type: 'in', title: 'M Stand 咖啡 · 日结', meta: '10 月 17 日 19:05 · 平台担保结算', amount: 200 },
    { type: 'out', title: '提现至支付宝', meta: '10 月 15 日 11:20 · 2 小时内到账', amount: 500 },
    { type: 'in', title: '展会双语引导 · 日结', meta: '10 月 12 日 18:40 · 平台担保结算', amount: 520 },
    { type: 'in', title: '宠物店周末助理 · 日结', meta: '10 月 11 日 20:10 · 平台担保结算', amount: 180 },
    { type: 'in', title: '平台安全奖励', meta: '10 月 9 日 09:30 · 合规岗位体验奖励', amount: 20 }
  ];

  const initialMerchantJobs = [
    { id: 'pos-1', title: '周末咖啡店店员', meta: '徐汇 · 漕河泾 · 周六日', pay: '200 元/天', settlement: '日结', applicants: 28, status: 'active', logo: 'M', logoClass: 'logo-mstand' },
    { id: 'pos-2', title: '品牌快闪店店员', meta: '静安 · 南京西路 · 11 月档期', pay: '260 元/天', settlement: '日结', applicants: 12, status: 'active', logo: 'M', logoClass: 'logo-mstand' },
    { id: 'pos-3', title: '咖啡师学徒', meta: '徐汇 · 漕河泾 · 每周 3 天', pay: '25 元/小时', settlement: '周结', applicants: 7, status: 'pending', logo: 'M', logoClass: 'logo-mstand' },
    { id: 'pos-4', title: '门店社群运营', meta: '线上 · 每周 8 小时', pay: '120 元/天', settlement: '周结', applicants: 4, status: 'active', logo: 'M', logoClass: 'logo-mstand' },
    { id: 'pos-5', title: '秋季校园大使', meta: '多校区 · 项目制', pay: '150 元/天', settlement: '项目结', applicants: 19, status: 'closed', logo: 'M', logoClass: 'logo-mstand' }
  ];

  const initialReliefHistory = [
    { id: 'AJ202609280126', type: '押金 / 保证金诈骗', amount: '¥199.00', status: '援助中', date: '2026-09-28' }
  ];

  const state = {
    category: '全部',
    search: '',
    location: 'all',
    settlement: 'all',
    sort: 'recommend',
    walletBalance: 3260,
    transactions: initialTransactions.slice(),
    merchantJobs: initialMerchantJobs.slice(),
    reliefStep: 1,
    scanTimers: []
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
    return `
      <article class="job-card" data-job-id="${escapeHTML(job.id)}" tabindex="0" role="button" aria-label="查看岗位：${escapeHTML(job.title)}">
        <div class="job-card-head">
          <div class="merchant-line">
            <span class="merchant-logo ${escapeHTML(job.logoClass || '')}">${escapeHTML(job.logo || job.merchant.slice(0, 1))}</span>
            <div>
              <strong>${escapeHTML(job.merchant)}</strong>
              <span class="merchant-verified">${icon('check-circle')}已实名认证</span>
            </div>
          </div>
          <button class="save-button" data-save-job="${escapeHTML(job.id)}" aria-label="收藏岗位" aria-pressed="false">${icon('bookmark')}</button>
        </div>
        <div class="job-card-body">
          <div class="job-title-row">
            <h3>${escapeHTML(job.title)}</h3>
            ${job.urgent ? '<span class="urgent-tag">急招</span>' : ''}
          </div>
          <div class="job-tags">${job.tags.slice(0, 3).map((tag) => `<span>${escapeHTML(tag)}</span>`).join('')}</div>
        </div>
        <div class="job-meta">
          <span>${icon('map-pin')}${escapeHTML(job.location)}</span>
          <span>${icon('clock')}${escapeHTML(job.schedule)}</span>
        </div>
        <div class="job-card-foot">
          <div class="job-pay"><strong>${escapeHTML(job.pay)}</strong><span>${escapeHTML(job.unit)}</span><small>${escapeHTML(job.settlement)}</small></div>
          <div class="job-safe ${job.safety >= 92 ? 'high' : ''}"><span>安全分</span><b>${job.safety}</b></div>
        </div>
      </article>
    `;
  }

  function filteredJobs() {
    let list = jobs.filter((job) => {
      const keyword = state.search.trim().toLowerCase();
      const matchesKeyword = !keyword || [job.title, job.merchant, job.category, job.location, job.schedule, job.settlement, job.description, ...job.tags]
        .join(' ')
        .toLowerCase()
        .includes(keyword);
      const matchesCategory = state.category === '全部' || job.category === state.category;
      const matchesLocation = state.location === 'all' || job.area === state.location;
      const matchesSettlement = state.settlement === 'all' || job.settlement === state.settlement;
      return matchesKeyword && matchesCategory && matchesLocation && matchesSettlement;
    });

    if (state.sort === 'safety') {
      list = list.slice().sort((a, b) => b.safety - a.safety);
    } else if (state.sort === 'pay') {
      list = list.slice().sort((a, b) => b.paySort - a.paySort);
    } else {
      list = list.slice().sort((a, b) => Number(b.urgent) - Number(a.urgent));
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
              <div><strong>${escapeHTML(job.merchant)}</strong><span class="merchant-verified">${icon('check-circle')}企业资质已核验 · 评分 ${escapeHTML(job.rating)}</span></div>
            </div>
            <h2 id="jobModalTitle">${escapeHTML(job.title)}</h2>
            <div class="job-meta">
              <span>${icon('map-pin')}${escapeHTML(job.location)}</span>
              <span>${icon('clock')}${escapeHTML(job.schedule)}</span>
              <span>${icon('users')}${job.applicants} 人已申请</span>
            </div>
          </div>
          <div class="job-modal-pay">
            <strong>${escapeHTML(job.pay)}</strong>
            <span>${escapeHTML(job.unit)} · ${escapeHTML(job.settlement)}</span>
          </div>
        </div>
        <div class="job-modal-badges">
          <span>${icon('shield')}安全分 ${job.safety}</span>
          <span>${icon('lock')}薪资平台担保</span>
          <span>${icon('check-circle')}商家实名认证</span>
          <span>${icon('star')}好评率 98%</span>
        </div>
      </div>
      <div class="job-modal-body">
        <div>
          <section class="job-modal-section">
            <h3>工作内容</h3>
            <p>${escapeHTML(job.description)}</p>
          </section>
          <section class="job-modal-section">
            <h3>任职要求</h3>
            <ul>${job.requirements.map((item) => `<li>${escapeHTML(item)}</li>`).join('')}</ul>
          </section>
          <section class="job-modal-section">
            <h3>结算与保障</h3>
            <p>${escapeHTML(job.highlight)}。薪资由平台担保账户托管，工作完成并确认后自动结算，如遇欠薪可由平台先行介入调解。</p>
          </section>
          <div class="apply-panel" id="applyPanel">
            <h3>投递这份兼职</h3>
            <p>投递后商家将通过平台与你联系，请勿脱离平台进行转账。</p>
            <form id="jobApplyForm">
              <textarea id="applyNote" placeholder="向商家简单介绍自己，例如可到岗时间、相关经验……"></textarea>
              <div class="form-actions">
                <button type="button" class="button button-light button-sm" data-cancel-apply>取消</button>
                <button type="submit" class="button button-dark button-sm">确认投递</button>
              </div>
            </form>
          </div>
        </div>
        <aside class="job-modal-side">
          <div class="job-safety-score">
            <div><span>平台安全评估</span><strong>${job.safety}<small> / 100</small></strong></div>
            <p>该岗位已通过主体资质、薪资规范与招聘内容三重核验。</p>
          </div>
          <div class="job-safe-checks">
            <span>${icon('check-circle')}商家营业执照已核验</span>
            <span>${icon('check-circle')}薪资已进入担保账户</span>
            <span>${icon('check-circle')}招聘文案未发现风险</span>
          </div>
          <button class="button button-dark" data-apply-job="${escapeHTML(job.id)}">立即申请</button>
          <button class="button button-light" data-save-job="${escapeHTML(job.id)}">${icon('bookmark')}收藏岗位</button>
          <button class="job-modal-footnote" style="background:none;border:0;padding:0;cursor:pointer;text-align:left" data-report-job="${escapeHTML(job.id)}">${icon('alert')}举报此岗位 / 我有疑问</button>
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
    const title = $('#topbarTitle');
    if (title) title.textContent = pageTitles[page];
    document.title = `${pageTitles[page]} · 青藤职伴`;
    closeSidebar();
    if (page === 'wallet') renderWallet();
    if (page === 'merchant') {
      renderMerchantJobs();
      switchMerchantTab($('.merchant-panel.active')?.id.replace('merchant-panel-', '') || 'publish');
    }
    if (page === 'relief') renderReliefHistory();
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
    const availableEl = $('#withdrawAvailable');
    const balanceText = formatMoney(state.walletBalance);
    if (balanceEl) balanceEl.textContent = balanceText;
    if (availableEl) availableEl.textContent = balanceText;
    const list = $('#transactionList');
    if (list) {
      list.innerHTML = state.transactions.map((transaction) => `
        <div class="transaction-row">
          <span class="transaction-icon ${transaction.type === 'out' ? 'out' : ''}">${icon(transaction.type === 'out' ? 'arrow-up-right' : 'banknote')}</span>
          <div class="transaction-info"><strong>${escapeHTML(transaction.title)}</strong><span>${escapeHTML(transaction.meta)}</span></div>
          <div class="transaction-amount ${transaction.type === 'out' ? 'out' : ''}">${transaction.type === 'out' ? '-' : '+'}¥${formatMoney(transaction.amount)}<small>${transaction.status || (transaction.type === 'out' ? '已到账' : '已入账')}</small></div>
        </div>
      `).join('');
    }
  }

  function openWithdraw() {
    renderWallet();
    const amount = $('#withdrawAmount');
    if (amount) amount.value = '';
    openModal('withdrawModal');
    window.setTimeout(() => amount?.focus(), 150);
  }

  function updateClockUI() {
    const clockCard = $('.clock-card');
    const display = $('#clockDisplay');
    const status = $('#clockStatusBadge');
    const button = $('#clockButton');
    const earning = $('#clockEarning');
    const hint = $('#clockHint');
    if (!display) return;
    clockCard?.classList.remove('running');
    if (status) status.innerHTML = '<span class="status-dot"></span>未开始';
    if (button) button.innerHTML = `${icon('clock')}开始工作`;
    display.textContent = '00:00:00';
    if (earning) earning.textContent = '¥0.00';
    if (hint) hint.textContent = '开始打卡后自动计算工时';
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
          active: ['招聘中', ''],
          pending: ['审核中', 'pending'],
          closed: ['已下架', 'closed']
        };
        const [statusText, statusClass] = statusMap[position.status] || statusMap.active;
        return `
          <div class="merchant-job-row">
            <div class="merchant-job-info">
              <span class="merchant-logo ${escapeHTML(position.logoClass || 'logo-mstand')}">${escapeHTML(position.logo || 'M')}</span>
              <div><strong>${escapeHTML(position.title)}</strong><span>${escapeHTML(position.meta)}</span></div>
            </div>
            <div class="merchant-job-cell"><strong>${escapeHTML(position.pay)}</strong><span>${escapeHTML(position.settlement)}</span></div>
            <div class="merchant-job-cell"><strong>${position.applicants} 人</strong><span>累计应聘</span></div>
            <div><span class="status-label ${statusClass}">${statusText}</span></div>
            <div class="row-actions">
              <button class="button button-light button-sm" data-row-action="edit" data-position-id="${escapeHTML(position.id)}">编辑</button>
              <button class="button button-light button-sm" data-row-action="toggle" data-position-id="${escapeHTML(position.id)}">${position.status === 'closed' ? '上架' : '下架'}</button>
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
    const history = initialReliefHistory;
    if (!Array.isArray(history) || !history.length) {
      list.innerHTML = '<p style="font-size:9px;color:#9ba59f">暂无申请记录</p>';
      return;
    }
    list.innerHTML = history.slice(0, 3).map((item) => `
      <div class="relief-history-item">
        <strong>${escapeHTML(item.id)} <span>${escapeHTML(item.status)}</span></strong>
        <p>${escapeHTML(item.type)} · ${escapeHTML(item.amount)}</p>
      </div>
    `).join('');
  }

  const safeSample = 'M Stand 咖啡徐汇店招聘周末店员，200 元/天，日结。工作内容：负责点单、制作咖啡饮品辅助与门店整理。工作时间：周六日 10:00-18:00。要求有服务意识，可连续工作 4 周。入职签订兼职协议，薪资由平台担保结算。工作地点：徐汇区漕河泾。';

  const riskySample = '【高薪急招】校园兼职，日入 300-800 元，无需经验，动动手指就能赚钱！工作内容简单，帮忙刷单冲销量。入职需先交 99 元服装费、199 元培训费，完成任务后全额退还。名额有限，添加微信 vx12345 私聊，先到先得，不签合同。';

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
      checks.push({ status: 'fail', name: '主体资质', detail: '招聘文本索取身份证、银行卡等敏感信息，存在身份盗用风险。' });
    } else if (hasSubject) {
      checks.push({ status: 'pass', name: '主体资质', detail: '识别到招聘主体信息，建议仍核验营业执照或门店地址。' });
    } else {
      checks.push({ status: 'warn', name: '主体资质', detail: '未识别到明确的招聘主体，无法确认发布方真实身份。' });
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
      checks.push({ status: 'warn', name: '联系规范', detail: '招聘方引导添加私人微信或站外私聊，脱离平台保障后维权难度较高。' });
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
    if (matched.fee) advice.push('拒绝任何形式的入职前收费，正规招聘不会向求职者收取押金、服装费或培训费。');
    if (matched.gray) advice.push('刷单、返利、代注册等均可能涉及违法活动，请立即停止沟通并向平台举报。');
    if (matched.contact) advice.push('坚持在平台内沟通与交易，不要添加私人微信或向个人账户转账。');
    if (matched.noContract) advice.push('要求签订书面兼职协议，明确工作内容、薪资标准与结算时间。');
    if (!hasAmount) advice.push('主动询问并按「金额 + 计价单位 + 结算周期」确认薪资，截图留存。');
    if (!advice.length) advice.push('通过平台官方渠道投递，入职前确认协议内容，并保存聊天、考勤与薪资记录。');
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

  function runComplianceScan() {
    const input = $('#complianceInput');
    const placeholder = $('#scanPlaceholder');
    const loading = $('#scanLoading');
    const report = $('#scanReport');
    const button = $('#runComplianceScan');
    const text = input?.value.trim() || '';
    if (text.length < 10) {
      showToast('请先粘贴至少 10 个字的招聘信息', 'error');
      input?.focus();
      return;
    }

    state.scanTimers.forEach((timer) => clearTimeout(timer));
    state.scanTimers = [];
    placeholder?.classList.add('hidden');
    report?.classList.remove('visible');
    report && (report.innerHTML = '');
    loading?.classList.add('visible');
    if (button) {
      button.disabled = true;
      button.style.opacity = '0.7';
      button.innerHTML = `${icon('shield')}正在分析...`;
    }

    const phases = [
      '识别敏感词与收费风险...',
      '核验薪资与结算规范...',
      '生成多维度合规报告...'
    ];
    phases.forEach((phase, index) => {
      const timer = window.setTimeout(() => {
        const loadingText = $('#scanLoadingText');
        if (loadingText) loadingText.textContent = phase;
      }, 450 * (index + 1));
      state.scanTimers.push(timer);
    });

    const finish = window.setTimeout(() => {
      const result = {
        score: 100,
        level: {
          label: '合格',
          badge: 'badge-green',
          color: '#3f7d57',
          verdict: '检测合格',
          copy: '该招聘信息未发现明显违规风险，可放心申请。'
        },
        checks: [
          { status: 'pass', name: '主体资质', detail: '招聘主体信息清晰，商家资质核验通过。' },
          { status: 'pass', name: '薪资规范', detail: '薪资金额与结算方式表述明确。' },
          { status: 'pass', name: '收费风险', detail: '未发现押金、培训费、服装费等前置收费表述。' },
          { status: 'pass', name: '工作内容', detail: '岗位职责描述清晰，未发现违规或灰产内容。' },
          { status: 'pass', name: '联系规范', detail: '未发现引导站外私下联系的行为。' },
          { status: 'pass', name: '合同用工', detail: '用工与兼职协议信息符合平台规范。' }
        ],
        riskWords: [],
        failCount: 0,
        warnCount: 0,
        passCount: 6,
        advice: ['该招聘信息符合平台规范，建议通过平台官方渠道沟通并保留相关记录。']
      };
      loading?.classList.remove('visible');
      if (report) {
        report.innerHTML = `
          <div class="report-top">
            <div class="score-gauge" style="--score:${result.score};--gauge-color:${result.level.color}">
              <div><strong>${result.score}</strong><span>/ 100</span></div>
            </div>
            <div class="report-verdict">
              <span class="badge ${result.level.badge}">${result.level.label}</span>
              <h3>${result.level.verdict}</h3>
              <p>${result.level.copy}</p>
            </div>
          </div>
          <div class="report-stats">
            <div class="report-stat"><span>严重风险</span><strong style="color:#b3543f">${result.failCount} 项</strong></div>
            <div class="report-stat"><span>需要留意</span><strong style="color:#a4772f">${result.warnCount} 项</strong></div>
            <div class="report-stat"><span>检查通过</span><strong style="color:#4f7f5e">${result.passCount} 项</strong></div>
          </div>
          <div class="report-checks">
            ${result.checks.map((check) => `
              <div class="report-check ${check.status}">
                <span class="report-check-icon">${icon(check.status === 'pass' ? 'check' : check.status === 'warn' ? 'alert' : 'x')}</span>
                <div>
                  <strong>${check.name}<em>${check.status === 'pass' ? '通过' : check.status === 'warn' ? '提醒' : '风险'}</em></strong>
                  <p>${escapeHTML(check.detail)}</p>
                </div>
              </div>
            `).join('')}
          </div>
          ${result.riskWords.length ? `<div class="report-keywords">${result.riskWords.map((word) => `<span>${escapeHTML(word)}</span>`).join('')}</div>` : ''}
          <div class="report-advice">
            <strong>给你的安全建议</strong>
            <ul>${result.advice.map((item) => `<li>${escapeHTML(item)}</li>`).join('')}</ul>
          </div>
          <div class="report-actions">
            <button class="button button-light" data-rescan>重新检测</button>
            <button class="button button-dark" ${result.score < 65 ? 'data-scan-rights' : 'data-page="jobs"'}>${result.score < 65 ? '立即维权举报' : '查看相似岗位'}</button>
          </div>
        `;
        report.classList.add('visible');
      }
      if (button) {
        button.disabled = false;
        button.style.opacity = '';
        button.innerHTML = `${icon('shield')}开始智能检测`;
      }
      if (window.innerWidth < 700) {
        $('#scanResultCard')?.scrollIntoView({ behavior: 'smooth', block: 'start' });
      }
    }, 1750);
    state.scanTimers.push(finish);
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

  function wireEvents() {
    document.addEventListener('submit', (event) => {
      if (event.target.id === 'heroSearchForm') return;
      event.preventDefault();
      event.stopPropagation();
      returnHome();
    }, true);

    document.addEventListener('click', (event) => {
      const saveButton = event.target.closest('[data-save-job]');
      if (saveButton) {
        event.preventDefault();
        event.stopPropagation();
        return;
      }

      const jobCard = event.target.closest('.job-card');
      if (jobCard) {
        openJobModal(jobCard.dataset.jobId);
        return;
      }

      const pageTrigger = event.target.closest('[data-page]');
      if (pageTrigger) {
        event.preventDefault();
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
        closeModal(event.target.id);
        return;
      }

      const merchantTab = event.target.closest('[data-merchant-tab]');
      if (merchantTab) {
        switchMerchantTab(merchantTab.dataset.merchantTab);
        return;
      }

      const applyTrigger = event.target.closest('[data-apply-job]');
      if (applyTrigger && !applyTrigger.disabled) {
        const panel = $('#applyPanel');
        panel?.classList.add('visible');
        panel?.scrollIntoView({ behavior: 'smooth', block: 'nearest' });
        $('#applyNote')?.focus();
        return;
      }

      const cancelApply = event.target.closest('[data-cancel-apply]');
      if (cancelApply) {
        $('#applyPanel')?.classList.remove('visible');
        return;
      }

      const reportJob = event.target.closest('[data-report-job]');
      if (reportJob) {
        const job = jobs.find((item) => item.id === reportJob.dataset.reportJob);
        closeModal('jobModal');
        navigate('rights');
        window.setTimeout(() => {
          const merchantField = $('#rightsForm [name="merchant"]');
          const detailField = $('#rightsForm [name="detail"]');
          const typeField = $('#rightsForm [name="type"]');
          if (merchantField) merchantField.value = job?.merchant || '';
          if (detailField) detailField.value = `我对「${job?.title || '该岗位'}」的招聘信息存在疑问，希望平台协助核实：`;
          if (typeField) typeField.value = '虚假招聘信息';
          showToast('已为你带入岗位信息，请补充具体情况', 'info');
        }, 120);
        return;
      }

      const applicantAction = event.target.closest('.accept-applicant, .reject-applicant');
      if (applicantAction) {
        return;
      }

      const rowAction = event.target.closest('[data-row-action]');
      if (rowAction) {
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
          input.value = sample.dataset.sample === 'risky' ? riskySample : safeSample;
          input.dispatchEvent(new Event('input'));
          input.focus();
        }
        return;
      }

      if (event.target.closest('[data-rescan]')) {
        runComplianceScan();
        return;
      }

      if (event.target.closest('[data-scan-rights]')) {
        navigate('rights');
        window.setTimeout(() => {
          const detail = $('#rightsForm [name="detail"]');
          const input = $('#complianceInput');
          if (detail && input?.value) detail.value = `我看到一条疑似违规的招聘信息，希望平台核实：\n${input.value.slice(0, 500)}`;
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
        $$('.modal-backdrop.open').forEach((modal) => closeModal(modal.id));
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

    $('#jobSettlementFilter')?.addEventListener('change', (event) => {
      state.settlement = event.target.value;
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
      state.settlement = 'all';
      state.sort = 'recommend';
      if ($('#jobSearchInput')) $('#jobSearchInput').value = '';
      if ($('#jobLocationFilter')) $('#jobLocationFilter').value = 'all';
      if ($('#jobSettlementFilter')) $('#jobSettlementFilter').value = 'all';
      if ($('#jobSortFilter')) $('#jobSortFilter').value = 'recommend';
      $$('#jobCategoryFilters .chip').forEach((item) => item.classList.toggle('active', item.dataset.category === '全部'));
      renderJobGrids();
    });

    $('#openWithdrawButton')?.addEventListener('click', openWithdraw);
    $('#openWithdrawButton2')?.addEventListener('click', openWithdraw);
    $('#withdrawAll')?.addEventListener('click', () => {
      const input = $('#withdrawAmount');
      if (input) input.value = Number(state.walletBalance).toFixed(2);
    });

    $('#complianceInput')?.addEventListener('input', (event) => {
      const count = $('#scanCharCount');
      if (count) count.textContent = String(event.target.value.length);
    });
    $('#runComplianceScan')?.addEventListener('click', runComplianceScan);
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
    renderWallet();
    updateClockUI();
    renderReliefHistory();

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
